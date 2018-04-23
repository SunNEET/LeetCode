class Solution {
public:
    //不使用STL語法的做法
    //用兩個index掃過去 i就正常整個掃 j負責把不是要移除的val的值存到他的位置
    //這個作法並不會真的讓vector變小,而是讓nums[0~j]的部分滿足題目的要求
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i=0;i<(int)nums.size();i++) {
            // 要移除的值就直接忽略,只留下要存的
            if (nums[i] == val)
                continue;
            nums[j++] = nums[i];
        }
        return j;
    }
};