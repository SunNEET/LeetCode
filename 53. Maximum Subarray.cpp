class Solution {
    /*
        DP: 直覺想法是如果自己+到前面為止的最大值沒辦法讓 sum 變得更大的話
        那只保留自己反而會比較大，後面的元素也應該只從我這個最大的開始考慮
    */
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], max_ending_here = nums[0];
        for (int i=1; i<nums.size(); i++){
            max_ending_here = max(max_ending_here+nums[i], nums[i]);
            res = max(res, max_ending_here);
        }
        return res;
    }
};