class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[256];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<s.length();i++)
            hash[s[i]]++;
        for(int i=0;i<t.length();i++)
            hash[t[i]]--;
        for(int i=0;i<256;i++)
            if(hash[i]!=0)
                return false;
        return true;
    }
};