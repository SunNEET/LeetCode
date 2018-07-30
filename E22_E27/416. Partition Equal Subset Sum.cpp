class Solution {
    // 轉個彎的背包問題
    // 要兩邊對半相等的話，代表要他們分別的sum必須是原本sum的一半
    // 換句話說，sum是奇數的話就必定不能拆成兩個一樣大的
    // 同背包: dp[i][j]代表到第i個為止的數字, 能否湊出j
    // 假如不拿第i個數字的話那 dp[i][j] = dp[i-1][j]
    // 拿第i個數字的話那 dp[i][j] = dp[i-1][j-nums[i]]
    // 由上得知狀態轉移方程: dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[j]] 
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums)
            sum += num;
        if(sum&1)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<vector<bool> > dp(n+1,vector<bool>(sum+1,false));
        // 初始化 填DP表格的邊邊, 這邊把nums的數字當作從1開始枚舉, 0列0行都是為了方便推算
        // 沒任何數字能拿也可以湊出0
        dp[0][0] = true;
        // 1~i都不拿就可以湊出0
        for(int i=1;i<=n;i++)
            dp[i][0] = true;
        // 沒拿任何數字不可能湊出sum
        for(int j=1;j<=sum;j++)
            dp[0][j];
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {
                // 不拿i 只看前面的能不能湊出j
                dp[i][j] = dp[i-1][j];
                // 用i-1是因為, 現在的i是為了方便推dp往後加過一位的,-1後才是他原本在nums對應的值
                if(j>=nums[i-1])
                    // 拿i的話, 就判斷到i-1為止, 能不能湊出j-nums[i-1]
                    // 因為這樣把nums[i-1]加上去, 到i為止就可以湊出j了
                    dp[i][j] = dp[i][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum];
    }
};