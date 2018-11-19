class Solution {
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