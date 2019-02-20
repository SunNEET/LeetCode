class Solution {
    /*
        Two pointer: 枚舉 nums[i]，然後往右看nums[left] 和 nums[right] 能否湊出 -nums[i]
        注意要跳過重複值的方法
        Time: O(N^2)
    */
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            int target = -nums[i];
            int left = i+1, right = nums.size()-1;
            while(left < right) {
                while(left < right && (nums[left] + nums[right]) > target) right--;
                if( left < right && nums[left] + nums[right] == target)
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                left++;
                while(left < right && nums[left] == nums[left-1]) left++;
            }
            // 如果下個 i 一樣就跳過，避免發生一樣的。
            while(i<(int)nums.size()-1 && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};

class Solution {
    /*
        HashMap + Set: 
        
        Time: O(N^2)
        
        [-4, -1, -1, 0, 1, 2] 
        
        hashTable -4 -1 0 1 2
                   0  1 1 1 1
                  
        [-4, -1, -1, 0, 1, 2] 
     i        ^
     j    ^
    */
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0; i<nums.size(); i++) hash[nums[i]]++;
        set<vector<int>> ans;
        for(int i=0; i<nums.size(); i++) {
            // 每當 i 往後移就減少當前的 hash[nums[i]]
            // 這是為了在查找 hash[target] 的時候，
            // 能夠看起來像以 i 為中心往右看，有剩多少 target
            // 否則回找到前面的
            hash[nums[i]]--;
            for(int j=0; j<i; j++) {
                int target = -nums[i]-nums[j];
                if(hash[target]>0) {
                    vector<int> tmp = {nums[j], nums[i], target};
                    sort(tmp.begin(), tmp.end());
                    ans.insert(tmp);
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};