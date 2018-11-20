class Solution {
    /*
        Almost same idea as 325.
        但這邊需要不只考慮最長的解而是一共有多少解，所以一樣的 prefixSum 出現時都必須記錄下來
        這樣就可以直接把該 prefixSum 對應的 indices 數量加到答案上

        Time Complexity: O(N)
    */
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        unordered_map<int,vector<int>> hash;
        hash[0].push_back(0);
        int cnt = 0;
        for(int i=1;i<=nums.size();i++) {
            if(hash.count(prefixSum[i]-k))
                cnt += (int)hash[prefixSum[i]-k].size();
            hash[prefixSum[i]].push_back(i);
        }
        return cnt;
    }
};