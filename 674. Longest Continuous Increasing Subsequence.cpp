class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_len = 0;
        int len = 0;
        for(int i=0;i<nums.size();i++) {
            if(i>0 && nums[i]<=nums[i-1]) len = 0;
            max_len = max(max_len, ++len);
        }
        return max_len;
    }
};