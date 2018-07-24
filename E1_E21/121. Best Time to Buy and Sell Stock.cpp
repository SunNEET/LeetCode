class Solution {
    // 因為每天的賣價只能往前比, 所以只要維護目前出現過的最低價, 還有最大profit就可以了
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int curProfit = 0;
        int curMin = prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i]-curMin > curProfit)
                curProfit = prices[i] - curMin;
            if(prices[i]<curMin)
                curMin = prices[i];
        }
        return curProfit;
    }
};