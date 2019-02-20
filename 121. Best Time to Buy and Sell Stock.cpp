class Solution {
    /*
        因為每天的賣價只能往前比，所以只要維護目前出現過的最低價，還有最大profit就可以了。
        Time: O(n)
        Space: O(1)
    */
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int cur_best = 0;
        int cur_min = prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i]-cur_min > cur_best)
                cur_best = prices[i] - cur_min;
            if(prices[i]<cur_min)
                cur_min = prices[i];
        }
        return cur_best;
    }
};