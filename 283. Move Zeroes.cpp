class Solution {
    /*
        用一個pointer non_zero_idx指向現在非0元素該填的位置
        遇到非0元素就把他swap到那邊然後non_zero_idx++
        這樣最後自然就只剩下0在最後面了
    */
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero_idx = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[non_zero_idx++], nums[i]);
            }
        }
    }
};