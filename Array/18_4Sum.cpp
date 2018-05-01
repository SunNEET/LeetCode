class Solution {
    // 直覺作法就是跟3sum一樣，只是變成雙層迴圈枚舉i跟j配合兩個pointer(k,l)來夾答案
    // 時間複雜度O(N^3)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        int k,l,sum;
        for(int i=0;i<nums.size()-3;i++) {
            for(int j=i+1;j<nums.size()-2;j++) {
                k = j+1;
                l = nums.size()-1;
                while(k < l) {
                    sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum == target) {
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        tmp.push_back(nums[l]);
                        ans.push_back(tmp);
                        tmp.clear();
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    } else if(sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
                while(i<nums.size()-2 && nums[j+1] == nums[j]) j++;
            }
            // 跳過一樣的數，避免重複解
            while(i<nums.size()-3 && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};