class Solution {
    /*
        避免重複的方法跟 40. Combination Sum II 一樣
        先排序，然後枚舉的時候遇到跟前一位一樣的就直接跳過

        Time complexity: O(n*2^n)

        clarify: 
        (1) For the return value, do we need to sort the possible subsets in a certain order?
    */
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        DFS(res, nums, cur, 0);
        return res;
    }
    void DFS(vector<vector<int>>& res, const vector<int>& nums, vector<int>& cur, int start) {
        res.push_back(cur);
        for(int i=start; i<nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) continue; // skip the same element
            cur.push_back(nums[i]);
            DFS(res, nums, cur, i+1);
            cur.pop_back();
        }
    }
};