class Solution {
    /*
        考慮最大的三個正整數相乘或是一個最大正整數*兩個最小負數
        p1*p2*p3 or p1*n1*n2
        Time:  O(N)
        Space: O(1)
    */
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            } else if(nums[i] > max3) {
                max3 = nums[i];
            }
            
            if(nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if(nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};