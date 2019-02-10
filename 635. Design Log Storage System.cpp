class LogSystem {
    /*
      利用 C++ STL multimap 來儲存 timestamp 跟 id 的 pair。
      - 使用 string 來做 key 是因為之後做 retrieve 是用 timestamp 來檢索
      - 由於 multimap 本身是一個平衡 BST，會把 data 用 key 來比較，這邊因為用 string 當key，
        所以就是用 string 排序。透過 lower_bound 取出第一個不小於檢索範圍起始的 timestamp，
        再用 upper_bound 取出第一個大於檢索範圍結束的 timestamp。
        (lower_bound, upper_bound-1)的部分就是答案了
      - 使用 multimap 而不是 map 是因為 timestamp 有可能重複，只有 id 是 unique 的

      Time complexity: put O(lg n), retrieve O(depends on the range of s and e)
      Does the value inside the return vector need to be in a certain order?
    */
private:
    multimap<string, int> storage;
    
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        storage.insert(make_pair(timestamp, id));
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> ret;
        if(gra=="Year") {
            s = s.substr(0,4) + ":01:01:00:00:00";
            e = e.substr(0,4) + ":12:31:23:59:59";
        } else if(gra=="Month") {
            s = s.substr(0,7) + ":01:00:00:00";
            e = e.substr(0,7) + ":31:23:59:59";
        } else if (gra == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        } else if (gra == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        } else if (gra == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        auto lb = storage.lower_bound(s), ub = storage.upper_bound(e);
        for(auto iter=lb; iter!=ub; iter++)
            ret.push_back(iter->second);
        return ret;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */