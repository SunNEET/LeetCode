class Solution {
    // 用內建的BST，multiset來做到nlogn 
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> window;
        for(int i=0;i<nums.size();i++) {
            window.insert(nums[i]);
            if(i-k+1>=0) {
                ans.push_back(*window.rbegin());
                window.erase(window.equal_range(nums[i-k+1]).first);
            }
        }
        return ans;
    }
};