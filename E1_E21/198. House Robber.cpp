class Solution {
    // 條件只有不能連抓兩個相鄰的, 所以像[3,2,1,9] 這種input最大應該會是 3+9=12
    // 用一個陣列dp[i]紀錄a[0~i]為止最大可以累加多少(不一定要把當前i算進去)
    // 第一種是把自己加算進去, 也就是間隔一個為止[0~i-2]的最大值加上自己的值
    // 第二種是不算自己的, 把前一個為止的最大值當作目前[0~i]範圍能變出的最大值
    // 所以狀態轉移可以想成 dp[i] = max(dp[i-2]+a[i], dp[i-1]) 
    
    // 邊界要注意的狀況比較多, 要小心
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) 
            return 0;
        if(len == 1)
            return nums[0]; 
        if(len == 2) 
            return max(nums[0], nums[1]);
        vector<int> dp;
        dp.resize(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2;i<len;i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[len-1];
    }
};