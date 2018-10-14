class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        auto i=s.begin(), j=i;
        while(i < s.end()) {
            if(*i!=' '){
                for(j = i+1; j!=s.end() && *j!=' '; j++);
                reverse(i,j);
                i=j;
                i++;
            } else {
                i = s.erase(i);
            }
        }
        if(*(s.rbegin())==' ') s.pop_back();
    }
};