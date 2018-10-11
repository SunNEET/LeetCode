class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256];
        int hash2[256];
        memset(hash,0,sizeof(hash));
        memset(hash2,0,sizeof(hash));
        for(int i=0;i<s.length();i++) {
            // 要兩邊的值都沒有map過才行
            // 如果s[i]沒map過但t[i]有, 代表s有別的值跟t[i]互相map了
            if(!hash[s[i]]) {
                if(!hash2[t[i]]) {
                    hash[s[i]] = t[i];
                    hash2[t[i]] = s[i];
                } else
                    return false;
            } else {
                // 有map過, 但值不對
                if(hash[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};