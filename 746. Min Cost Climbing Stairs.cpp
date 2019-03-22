class Solution {
    /*
        簡單的爬樓梯DP，初始化好dp[0]和dp[1]後
        一直考慮前兩層的最小值和當前的cost就好
        最後的答案可能是倒數第一或第二階(因為可以走一步或兩步)
        回傳小的那個
        Time: O(n)
        Space:O(n)
    */
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() < 3) return min(cost[0], cost[1]);
        int goal = cost.size() + 1;
        vector<int> DP(cost.size()+1, INT_MAX);
        DP[0] = 0, DP[1] = cost[0];
        for(int i=2; i<=cost.size(); i++) {
            int pre_min_cost = min(DP[i-1], DP[i-2]);
            DP[i] = min(DP[i], pre_min_cost + cost[i-1]);
        }
        return min(DP[goal-1], DP[goal-2]);
    }
};