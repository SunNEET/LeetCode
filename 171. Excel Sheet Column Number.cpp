class Solution {
    // 水題
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(int i=s.length()-1,j=0;i>=0;i--,j++) {
            ans += (s[i]-'A'+1)*(int)pow(26,j);
        }
        return ans;
    }
};