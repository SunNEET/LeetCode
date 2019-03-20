class Solution {
    /*
        對於一個大小為n的array, 我想把它排成nums=[1,2,...,n]的形式
        讓數字i出現在 position i-1 的地方
        這樣掃過去的時候遇到 nums[i] != i+1 的，就知道他是第一個miss的最小 positive number
        換過去的技巧，其實就是用 swap(nums[i] ) if(nums[i]>0 && < n)
    */
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 1;
        for(int i=0; i<nums.size(); i++)
            // keep swaping the swapped value if it is positive number and no duplicate
            while(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i]) 
                swap(nums[i], nums[nums[i]-1]);
        for(int i=0; i<nums.size(); i++)
            if(nums[i]!=i+1)
                return i+1;
        return nums.size()+1;
    }
};