class Solution {
    /*
        令DP[i]為換到金額 i 需要的最少硬幣數量，
        預設為INT_MAX, 如果做完回圈後還是INT_MAX那就表示換不到
        先枚舉 money 在枚舉 coin
        Time: O(n*amount)
        Space O(amount);
    */
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount+1, INT_MAX);
        DP[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int j=0; j<coins.size(); j++) {
                if (coins[j] <= i && DP[i-coins[j]]!=INT_MAX)
                    DP[i] = min(DP[i], DP[i-coins[j]]+1);
            }
        }
        return DP[amount] != INT_MAX ? DP[amount] : -1;
    }
};