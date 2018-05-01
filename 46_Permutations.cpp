class Solution {
    //套熟悉的DFS寫法, 用visited紀錄枚舉過(走過)的點, 走到深度==數列長度就可以存入答案 
public:
    bool visited[100000];
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        memset(visited,0,sizeof(visited));
        dfs(0, tmp, nums, res);
        return res;
    }
    
    void dfs(int pos, vector<int> &tmp, vector<int> &nums, vector<vector<int>> &res) {
        if (pos == nums.size()) {
            res.push_back(tmp);
            return;
        } else {
            for(int i=0;i<nums.size();i++) {
                if (!visited[i]) {
                    tmp.push_back(nums[i]);
                    visited[i]=true;
                    dfs(pos+1, tmp, nums, res);
                    tmp.pop_back();
                    visited[i]=false;
                }
            }
        }
        return;
    }

};