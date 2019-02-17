class RandomizedSet {
    /*
        Solution: 使用一個 vector 來當做 set，用一個 map 來存一個 val 在 vector 裡的 index。
        關鍵在移除某個 val 的時候，並不是直接移除它而是把 vector 尾端的元素複製到 val 的位置(透過map存的index)
        然後讓 last element 的 index 改成 val 的位置。再來就可以用O(1)時間 pop 掉尾巴的元素

        Edge cases: RandomizedSet obj = new RandomizedSet();
        (1) 一開始直接 obj.remove() 
        (2) 重複 insert 同一個 val，然後 remove(val) 數次
    */
private:
    vector<int> nums;
    unordered_map<int,int> v_idx;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(v_idx.count(val)) return false;
        nums.push_back(val);
        v_idx[val] = (int)nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!v_idx.count(val)) return false;
        int last = nums.back();
        
        // In here, not only copy the last value to where val is,
        // but also change the index of the last value to where val is.
        v_idx[last] = v_idx[val]; 
        nums[v_idx[last]] = last;
        // a[...val...last] => a[..last...last]
        // index of the last value: nums.size()-1 => (position of val)
        v_idx.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */