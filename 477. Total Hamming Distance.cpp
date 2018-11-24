class Solution {
    /* naive way: 枚舉所有 pairs，存下他們所有的 x^y，然後在掃一次這些 x^y 統計有多少個 1
    Time Complexity O(N^2)
    Space O(N) => MLE
    
    最優解： 不是枚舉 pairs 而是枚舉每一位 bit，然後把每一位裡 0 和 1 的數量乘起來加到總數
    Time Complexity O(32*N)
    圖解 以 sample input 為例
    bit   ones      zero        pairs
    0     []        [4,14,2]    0       (三個數的第0位都一樣，所以沒有distance)
    1     [2,14]    [4]         2       (2*1 -> [2,4], [14,4] 的第1位都會分別讓distance增加)
    2     [4,14]    [2]         2       (2*1 -> [4,2], [14,2] ditto)
    3     [14]      [4,2]       2       (1*2 -> [14,4], [14,2] ditto)
    total = 2+2+2 = 6
    */
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int mask = 1;
        for(int i=0; i<32; i++) {
            int cnt1 = 0;
            for(int j=0; j<nums.size(); j++)
                if(nums[j]&mask) cnt1++;
            res += cnt1 * (nums.size() - cnt1);
            mask <<= 1;
        }
        return res;
    }
};