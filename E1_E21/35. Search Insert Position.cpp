class Solution {
    // 用lower_bound做二分搜找滿足的情況
    // 因為不會有重複元素, 所以是用lower還是upper就沒差了
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};