class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<int> dp(len+1);
        dp.clear();
        int ans = 0;
        // 起點值, 方便計算, 這樣枚舉時要index往後加ㄧ
        dp[0]=0;
        for(int i=1;i<=len;i++){
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[j]+1,dp[i]);
                    ans = max(dp[i], ans);
                }
            }
        }
        for(int i=0;i<=len;i++)
            printf("%d ",dp[i]);
        return ans;
    }
};