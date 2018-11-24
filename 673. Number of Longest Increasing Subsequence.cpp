class Solution {
    /*
        DP: DP[i]存的是一組pair，代表序列結束在i時 {能湊出的LIS長度, 這個長度的LIS有多少組}。
        枚舉 i 然後往前看(枚舉j)，找出可以接的(比nums[i]小的)dp[j]
        Time Complexity: O(N^2)
    */
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, maxLen = 1;
        vector<pair<int,int> > dp(nums.size(),{1,1}); // dp[i]: {length, number of LIS which ends with nums[i]}
        for(int i=0; i<n; i++) { // 固定 i, 往前面找可以接(小於它)的 j
            for(int j=i; j>=0; j--) {
                if(nums[i] > nums[j]) {
                    // dp[j].first + 1 代表的是從j往後接，加上i的話，新的LIS會形成的長度
                    if(dp[i].first == dp[j].first + 1) 
                        dp[i].second += dp[j].second;
                    else if(dp[i].first < dp[j].first + 1) 
                        dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if(maxLen == dp[i].first) res += dp[i].second;
            if(maxLen < dp[i].first) {
                maxLen = dp[i].first;
                res = dp[i].second;
            }
        }
        return res;
    }
};