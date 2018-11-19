class Solution {
    /*
        跟 5. 的做法差不多，只是每次找到 OK 的就把 cnt+1
    */
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.length();i++) {
            ans += extCenter(s,i,i);
            ans += extCenter(s,i,i+1);
        }
        return ans;
    }
    
    int extCenter(const string& s, int left, int right) {
        int cnt = 0;
        while(left>=0 && right<s.length() && s[left]==s[right]) {
            left--;
            right++;
            cnt++;
        }
        return cnt;
    }
};