class Solution {
    /*
        爬樓梯的改良版, 令dp[i]為到i這個字元為止有幾種"組合"
        而到dp[i]為止能有的組合實際上就是爬樓梯加幾個條件
        如果要把到dp[i-1]的組合數加上去, 那表示當前的i自己可以成為一個字母對應的數字
        1~9當然沒問題, 但如果是0的話就沒有能對應的字母, 所以
        dp[i-2]的話則是要考量 s[i-1]s[i]所構成的二位數是否合法, 也就是介於10~26

        Time: O(N)
        Space: O(N)
    */
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        // 一樣初始化dp起點0 把對應的i都往後推一位
        dp[0]=1;
        for(int i=1;i<=n;i++) {
            int ss = s[i-1]-'0';
            if( ss!=0 )
                dp[i] += dp[i-1];
            if(i>1) {
                int dd = (s[i-2]-'0')*10+(s[i-1]-'0');
                if( dd>=10 && dd <= 26)
                    dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};