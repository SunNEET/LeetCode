class Solution {
    /*
        Expand Around Center 作法: 
        We can see that a palindrome mirrors around its center. 
        So, a palindrome can be expanded from its center. 
        I'll enumerate every center point and expand from it.
        Cause a center might be at between two centers, so I'll also take that into account.

        Time Complexity: O(N^2)
        Space Complexity: O(1)
    */
public:
    string longestPalindrome(string s) {
        if( s.length() == 0 ) return "";
        int len = 1, idx = 0;
        for(int i=0;i<s.length()-1;i++) {
            extCenter(s,i,i,len,idx);
            extCenter(s,i,i+1,len,idx);
        }
        return s.substr(idx,len);
    }
    
    void extCenter(string s, int left, int right, int& len, int& idx) {
        while(left >=0 && right < s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        if(right-left-1 > len) {
            len = right-left-1;
            idx = left+1;
        }
    }
};

class Solution {
    /* DP approach:
        Define DP[i][j], if string s[i~j] is palindrome, DP[i][j] is true.
        DP[i][j] would be true if DP[i+1][j-1] and s[i]==s[j] are true.
        Initially we set DP[i][i] to true and DP[i][i+1] to true if s[i] == s[i+1]
        Then enumerate length of substring and starting position

        Time: O(N^2)
        Space: O(N^2)
    */
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(!n) return "";
        vector<vector<bool>> DP(s.length(),vector<bool>(s.length(),false));
        int sLen = 1, sIdx = 0;
        for(int i=0;i<s.length();i++) 
            DP[i][i]=true;
        for(int i=0;i<s.length()-1;i++) {
            if(s[i]==s[i+1]){
                DP[i][i+1]=true;
                sIdx = i;
                sLen = 2;
            }
        }
        for(int len=3;len<=n;len++) {
            for(int i=0;i<n-len+1;i++) {
                int j = i+len-1;
                if(DP[i+1][j-1] == true && s[i] == s[j]) {
                    DP[i][j] = true;
                    if(len > sLen) {
                        sLen = len;
                        sIdx = i;
                    }
                }
            }
        }
        return s.substr(sIdx,sLen);
    }
};