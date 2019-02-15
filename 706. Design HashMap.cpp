class MyHashMap {
    /*
        根本不是easy的題目
        用 vector 存 list<pair<int,int>> 來維護一個 hashtable，
        並且假設 table 的 row 有 10000 個，所以超過 10000 的數字會被 mod 然後接到該的list最尾端。
        
        put 的時候就是去取 key%size 這個 list (等同table的row)
        這邊要注意用 reference variable 來拿這個list
        這樣等等的更改才會反應到 table 上
        
        get 就不一定要用 reference，用了就是省點空間，不用也沒差
        反正就是 return 取出的 list 裡 key 對應的值而已
        
        remove 用 list 的 remove_if，這個 function 會用後面傳進去的 function
        ，如果回傳 true 那就把該元素刪掉。
        `list.remove_if([key](auto& val) { return val.first == key; });`
          - [key]是為了讓 inner function 能看到 outer function 的變數，因為c++不像
            JavaScript的closure會自動把外面的變數包進去
        
        
        Time: Time complexity is O(1) at the beginning, but it will degrade to O(N) as data gets bigger
        Space: O(N)
    */
private:
    vector<list<pair<int,int>>> table;
    const int size = 10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        table.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto& list = table[key%size];
        for(auto& val : list) {
            if(val.first==key) {
                val.second = value;
                return;
            }
        }
        // list.push_back(make_pair(key,value));
        list.emplace_back(key,value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        const auto& list = table[key%size];
        if(list.empty()) return -1;
        for(const auto& val : list) {
            if(val.first == key)
                return val.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& list = table[key%size];
        list.remove_if([key](auto& val) { return val.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */