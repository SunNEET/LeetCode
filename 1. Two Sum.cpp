class Solution {
    // 這題可以直接雙層迴圈全部組一遍，但這樣複雜度O(N^2)，還可以改進。
    // 這種組合類的題目都可以用類似的技巧，就是用目標sum - 當前a[i]，然後判斷是否有滿足這值的元素存在
    // 可以用unorder_map先把值存起來，這樣之後查找就O(1)，最後的複雜度是O(N)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()<=1) return ans;
        unordered_map<int,int> hash;
        for(int i=0;i<(int)nums.size();i++) {
            hash[nums[i]] = i;
        }
        for(int i=0;i<(int)nums.size();i++) {
            int rest = target - nums[i];
            if(hash.find(rest)!=hash.end()) {
                // 選到同一個位置的情況要排除
                if (hash[rest] == i) 
                    continue;
                ans.push_back(min(i, hash[rest]));
                ans.push_back(max(i, hash[rest]));
                return ans;
            }
        }
    }
};