class Solution {
    /*
        複雜DP: DP[i] refers to how many combination of target i can be made, using array nums
        https://blog.xiadong.info/2016/07/29/leetcode-377-combination-sum-iv/
        Time complexity: O(target * |nums|)
    */
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 1;
        return dfs(nums, dp, target);
    }
private:
    int dfs(vector<int>& nums, vector<int>& dp, int target) {
        if(dp[target] != -1) return dp[target];
        int cnt = 0;
        for(int i = 0; (int)i<nums.size(); i++) {
            if(nums[i] <= target) {
                cnt += dfs(nums, dp, target - nums[i]);
            }
        }
        dp[target] = cnt;
        return cnt;
    }
};