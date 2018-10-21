class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> ans((int)dict.size());
        vector<int> prefix((int)dict.size(),1);
        unordered_map<string,int> cnt;
        for(int i=0;i<dict.size();i++) {
            ans[i] = makeAbbr(dict[i], prefix[i]);
            cnt[ans[i]]++;
        }
            
        while(true) {
            bool uniq = true;
            for(int i=0;i<dict.size();i++) {
                if(cnt[ans[i]]>1) {
                    prefix[i]++;
                    ans[i] = makeAbbr(dict[i], prefix[i]);
                    cnt[ans[i]]++;
                    uniq = false;
                }
            }
            if(uniq)
                break;
        }
        return ans;
    }
    
    string makeAbbr(string s, int k) {
        // 倒數第二位不用縮成1, 保持原樣
        if(k >= s.length()-2) {
            return s;
        }
        string res = "";
        res += s.substr(0,k) + to_string(s.length()-1-k) + s[s.length()-1];
        return res;
    }
};