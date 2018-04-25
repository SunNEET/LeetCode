class Solution {
public:
    // 因為有排序過，所以相同的數字一定會緊靠在一起，一直判斷nums[i]是否等於nums[j]，直到找到不是的為止(也就是不重複的)。
    // 把找到的非重複值存到j的下一個，然後遞增j。
    // j最後會成為移除重複後的數組的最後一個index，所以size就是return j+1
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0) return 0;
        
        int j = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[j]==nums[i])
                continue;
            nums[++j] = nums[i];
        }
        return j+1;
    }
};