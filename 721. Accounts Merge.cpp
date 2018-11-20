class Solution {
    /*
        關鍵在把 list 建成圖，可以建成無向圖後用DFS解，也可以用 parent 存 group 關係然後用 union find 解。
        Union find 作法：用三個 map 分別存 parent, name 和 答案的集合
        (1) 先初始化成每個 email 的 parent 是自己，owner 都是第 0 個
        (2) 做 union find 
        (3) 掃一次全部的 email, 根據剛剛 union find 的結果插入到對應的 set 裡 (set會順便做排序)
        (4) 把 set 的 value 存到 vector, 然後開頭插入 name

        Time Complexity: O(n*mlog(n*m)), say n is the number of total lists, 
        m is the number of strings of a list. That log comes from insert operation of set.
    */
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        if(accounts.size() == 0) return ans;
        unordered_map<string, string> parent; // keep groups
        unordered_map<string, string> owner; // keep names
        unordered_map<string, set<string>> unions; // for outputing answer
        
        // Init, every account belongs to its own group at first
        for(int i=0;i<accounts.size();i++) {
            for(int j=1;j<accounts[i].size();j++) {
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        
        // Make each email of a list points their group
        for(int i=0;i<accounts.size();i++) {
            string p = find(accounts[i][1], parent); // get the group
            for(int j=2;j<accounts[i].size();j++)
                parent[find(accounts[i][j], parent)] = p;
        }
        
        for(int i=0; i<accounts.size(); i++) 
            for(int j=1; j<accounts[i].size(); j++)
                unions[find(accounts[i][j], parent)].insert(accounts[i][j]);
        
        for(auto it = unions.begin() ; it!=unions.end(); it++) {
            vector<string> emails(it->second.begin(), it->second.end());
            emails.insert(emails.begin(), owner[it->first]);
            ans.push_back(emails);
        }
        return ans;
    }
    string find(string s, unordered_map<string, string>& p) {
        if(p[s]==s)
            return s;
        return p[s] = find(p[s], p);
    }
};