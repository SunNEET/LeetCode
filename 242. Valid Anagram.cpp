class Solution {
    // 直接Hash, 字母count相等就是anagram
public:
    bool isAnagram(string s, string t) {
        int hash[26];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<s.length();i++)
            hash[s[i]-'a']++;
        for(int i=0;i<t.length();i++)
            hash[t[i]-'a']--;
        for(int i=0;i<26;i++)
            if(hash[i])
                return false;
        return true;
    }
};