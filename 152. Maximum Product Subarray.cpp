class Solution {
    /*
        一直維護到目前為止能做出的最大product，和最小product
        重點在遇到負數的時候要把最大最小 swap，因為等下會乘上負數，此時最小的可能會變最大
        最大的可能會變最小
        跟53. Maximum Subarray的想法類似，如果如果乘上nums[i]沒辦法變得更大或更小的話
        那就直接保留nums[i]，這樣後面的元素也只會從 i 開始考慮
    */
public:
    int maxProduct(vector<int>& nums) {
        if(!nums.size()) return -1;
        int res = nums[0];
        
        for(int i=1, max_sofar=res, min_sofar=res; i<nums.size(); i++) {
            if(nums[i] < 0) swap(max_sofar, min_sofar);
            max_sofar = max(nums[i], max_sofar*nums[i]);
            min_sofar = min(nums[i], min_sofar*nums[i]);
            res = max(res, max_sofar);
        }
        return res;
    }
};