class Solution {
    /*
        最佳解有點燒腦，要用 prefix sum and module 同時處理。
        Suppose we have a cumulative sum from 0 to index i, and its remainder after modulo k is "rem".
        If there is a index j after the index i making subarray[i+1~j] sum up to multiple of k, 
        then the cumulative sum from 0 to index j can be write as "rem + n*k".
        So, if we want to check if the sum of the subarray[i+1~j] is a multiple of k,
        we just need to observe if the remainder of cumulative sum upto j has been previously seen before.
        E.g.
        [0,...,i,...,j,...]
               ^     ^ (2)if the sum of subarray[i+1~j] is multiple of k,
               ^          then cumulative sum upto j will be "rem + n*k"
               ^
               (1)cumulative sum up to i is "sum[i]", and after module k, the value becomes "rem"
                
        Time complexity: O(n)
        Edge cases: 
        (1) [0],0 -> false
        (2) [5,2,4],5 -> false
        (3) [0,0],100 ->true
        (4) [1,5],-6 -> true
        (5) [0,0],0 -> true
        
        Time Complexity: O(N)
        
    */
public:
    bool checkSubarraySum(vector<int>& nums, int k) {      
        unordered_map<int,int> hash; // used to keep track of indices of different remainder
        hash[0] = -1; // When a sum%k==0, it means the subarray starting from 0 to its index is multiple of k, 
        // set hash[0] to -1 is just to make us easier to calculate the size of the subarray later.
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            if(k) sum %= k;
            if(hash.count(sum) > 0){
                if(i - hash[sum] > 1)
                    return true;
            } else
                hash[sum] = i;
        }
        return false;
    }
};