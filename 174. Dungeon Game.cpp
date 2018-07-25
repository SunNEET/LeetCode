class Solution {
    // 重點: 令狀態轉移方程dp[i][j]為從(i,j)出發的話，需要多少起始血量
    // 依序從公主的房間回推回騎士在的位置。
    // 而每一格出發所需要的最低血量，其實就是先看他右邊或下面哪格，需要的最低血量比較低
    // 我們當然是走血量需求比較低的那格，所以就用那格min(dp[i+1][j],dp[i][j+1])的最低血量
    // 減掉目前當作起點的這格(dungeon[i][j])的值
    // 
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                printf(" %d",dp[i][j]);
            }
            puts("");
        }
        return dp[0][0];        
    }
};