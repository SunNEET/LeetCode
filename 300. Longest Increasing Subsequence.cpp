class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<int> dp(len);
        // init
        for(int i=0;i<len;i++)
            dp[i]=1;
        
        int ans = 1;
        for(int i=0;i<len;i++){
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[j]+1,dp[i]);
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};