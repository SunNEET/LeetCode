class Solution {
    /*
        用兩個變數s1, s2來維護當前看到的最小和次小值，按照先比 s1, 再 s2 的順序
        後面新的最小值把 s1, s2 蓋掉也沒有關係，因為表示當前的狀況裡他不會是第三個遞增的數。
        而且如果這個數比目前的 s2 大，那它自然也會比原本的 s1 大。
        
        e.g. [4,2,3,1,5]
        s1 = 2, s2 = 3 遇到 1
        -> s1 = 1 s2 = 3 遇到 5
    */
public:
    bool increasingTriplet(vector<int>& nums) {
        int s1 = INT_MAX, s2 = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= s1)
                s1 = nums[i];
            else if(nums[i] <= s2)
                s2 = nums[i];
            else 
                return true;
        }
        return false;
    }
};