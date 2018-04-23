class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.empty()) return true;
        //對s->t做一次hash,有出現一對多就是false
        map<char,char> mcc1;
        for(int i=0;i<s.length();i++) {
            if ( mcc1.count(s[i]) == 0 ) {
                mcc1[s[i]] = t[i];
            } else {
                if (mcc1[s[i]] != t[i])
                    return false;
            }
        }
        map<char,char> mcc2;
        //在對t->s做一次hash,上面的判斷抓不出ex: s:aoce,t:fooc 的情況
        for(int i=0;i<t.length();i++) {
            if ( mcc2.count(t[i]) == 0 ) {
                mcc2[t[i]] = s[i];
            } else {
                if (mcc2[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};