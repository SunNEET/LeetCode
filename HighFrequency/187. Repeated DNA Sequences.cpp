class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> hash;
        vector<string> ans;
        // edge case
        if(s.length()<10) return ans;
        
        for(int i=0;i<s.length()-9;i++) {
            string tmp = s.substr(i,10);
            hash[tmp]++;
        }
        for(auto it = hash.begin();it!=hash.end();it++) {
            if(it->second > 1)
                ans.push_back(it->first);
        }
        return ans;
    }
};