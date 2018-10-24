/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // DFS计算节点高度，hash 保存答案
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> hash;
        int maxh = dfs(root, hash);
        for(int i=1;i<=maxh;i++) {
            ans.push_back(hash[i]);
        }
        return ans;
    }
    
    int dfs(TreeNode* cur, unordered_map<int,vector<int>>& hash) {
        if(!cur) 
            return 0;
        int lh = dfs(cur->left, hash);
        int rh = dfs(cur->right, hash);
        int curh = max(lh, rh)+1;
        hash[curh].push_back(cur->val);
        return curh;
    }
};