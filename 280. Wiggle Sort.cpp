class Solution {
    // 題意可以理解成, 要把他排成 偶數位的要比奇數位的大
    // 而且要in-place, 不能另外再用一個array存數字在照規則填進去
    // 
    // 這樣做其實也不難,只要一直確保當前的nums[i]是否有滿足條件:
    // 1. 如果是偶數位, nums[i]>=nums[i-1]
    // 2. 如果是奇數位, nums[i]<=nums[i-1]
    // 這樣就可以一次掃過去了,不用sort
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        for(int i=1;i<n;i++){
            if((i&1) && nums[i]<nums[i-1] || !(i&1) && nums[i]>nums[i-1]) 
                swap(nums[i], nums[i-1]);
        }
    }
};