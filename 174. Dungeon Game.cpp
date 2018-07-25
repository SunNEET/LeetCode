class Solution {
    // 重點: 令狀態轉移方程dp[i][j]為從(i,j)出發的話，需要多少起始血量才能到終點
    // 依序從公主的房間回推回騎士在的位置。
    // 而每一格出發所需要的最低血量，其實就是先看他右邊或下面哪格，需要的最低血量比較低
    // 我們當然是走血量需求比較低的那格，所以就用那格min(dp[i+1][j],dp[i][j+1])的最低血量
    // 減掉目前當作起點的這格(dungeon[i][j])的值

    // 相減之後若是正值，代表還需要更高的最低血量, 才能從(i,j)出發到血量比較低的下個點
    // 而這最低血量就是剛剛相減完的值 dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j]

    // 相減之後若是負值，代表這格不但是正的，而且加的血量足夠你直接接著採需求比較低的那一格了
    // 這情況直接將dp[i][j]設為1就好，表示從這格出發的話，我只要有1滴血就夠了(因為他加的比接下來最佳路徑扣的多)

    // 兩種情況寫在一起就是dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j])
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        // 方便DP回推, 多弄一個最外圈
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        // 公主的右跟下初始成1，就可以推出公主一開始的點要多少血量了，免得初始化跟特判的一些問題
        dp[m][n-1] = 1; 
        dp[m-1][n] = 1;
        for (int i=m-1; i>=0;--i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];        
    }
};