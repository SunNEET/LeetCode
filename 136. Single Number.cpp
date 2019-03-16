class Solution {
    /*
        Using XOR 
        because if we make a value do XOR with same value twice, it will back to the origin
        A XOR B = A^B
        A^B XOR B = A
        Time: O(N)
        Space: O(1)
    */
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};