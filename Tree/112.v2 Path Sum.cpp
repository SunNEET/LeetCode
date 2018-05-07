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
    // 不用set的小優化法, 讓dfs回傳bool
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root,0,sum);
    }
    bool dfs(TreeNode* cur, int cur_sum, int target_sum) {
        if(!cur) 
            return false;
        else {
            cur_sum += cur->val;
            if(!cur->left&&!cur->right) {
                return cur_sum == target_sum;
            }
            bool lf = dfs(cur->left ,cur_sum,target_sum);
            bool rt = dfs(cur->right,cur_sum,target_sum);
            return lf || rt;
        }
    }
};
