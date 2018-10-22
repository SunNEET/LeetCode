class Solution {
    // 複雜度O(N*(M+26)), 為了省去sort這個步驟
    // 需要多用一個字串cnt來存每個字元的出現次數, 並且用這個字串當作map的key
    // 例如 "abc" 的 cnt 就會是 "#1#1#1#0....."
    // "bac" 也會跟上面一樣
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> hash2;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++) {
            int hash1[26]={};
            for(int j=0;j<strs[i].length();j++)
                hash1[strs[i][j]-'a']++;
            string cnt = "";
            for(int i=0;i<26;i++)
                cnt += "#" + to_string(hash1[i]);
            hash2[cnt].push_back(strs[i]);
        }
        for(auto it = hash2.begin();it!=hash2.end();it++)
            ans.push_back(it->second);
        return ans;
    }
};