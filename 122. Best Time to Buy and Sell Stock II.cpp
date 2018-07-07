class Solution {
    // 因為可以做複數次操作, 要湊出最大獲益的方法
    // 其實就是把每一段非遞減區段的"尾-頭"
    // 然後各段加起來就行了
public:
    int maxProfit(vector<int>& prices) {
        int len = (int)prices.size();
        if(!len) return 0;
        int res = 0;
        int curMin = prices[0];
        for(int i=1;i<len;i++){
            // 判斷區段是否已經不是非遞減
            // 重設此區段新的最小值, 並且把剛剛區段的"尾-頭"累加進res
            if(prices[i]<prices[i-1]) {
                res += prices[i-1] - curMin;
                curMin = prices[i];
            }
            // 區段一路非遞減到end的情況要特判, 把值累加進res
            if(i==(len-1) && prices[i]>=prices[i-1])
                res += prices[i] - curMin;
        }
        return res;
    }
};