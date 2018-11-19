class Solution {
    /* 
        跟 209. 很像但解法全然不同，而且的這題要求是 equals k
        一樣先預處理 nums 存成 prefixSum，然後用一個 map 紀錄某個 prefix 最早出現的 index
        Sum of nums[i~j](=k) = prefix[j] - prefix[i-1]
        => prefix[i-1] = prefix[j] - k
        因此我們從左往右掃 nums 相當於是枚舉index j，然後往左找
        有沒有符合條件的 index i-1

        Tips: 為了方便計算，prefixSum 都往後推一位
              然後hash要初始化 -> hash[0]=0，代表 0 在最開始就出現過了
    */
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        
        vector<int> prefixSum(nums.size()+1, 0);
        unordered_map<int,int> hash;
        for(int i=1;i<=nums.size();i++)
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        int sum = 0, ans = 0;
        hash[0] = 0;
        for(int i=1; i<=nums.size(); i++) {
            int sum = prefixSum[i];
            if(hash.count(sum-k)>0){
                // what hash[sum-k] gives us is the index (i-1) of the prefix[i-1] that equals prefix[j] - k.
                // so we don't need to + 1
                ans = max(ans, i-hash[sum-k]);
            }
            if(hash.count(sum) == 0)
                hash[sum] = i;
        }
        return ans;
    }
};