class Solution {
    // 雙指針掃過去可解決 T:O(N), S:O(1)
    // i用來枚舉nums, j用來指向要replace的位置
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int n = (int)nums.size();
        while(i<n) {
            while(i<n && nums[i]==val) 
                i++;
            if(i<n)
                nums[j++] = nums[i++];
        }
        return j;
    }
};