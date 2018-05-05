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
    // 直接traverse, 坐到哪就把val按照depth塞進去
    // 只是要先抓出深度, 才知道雙層vectorㄧ維要開多大
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int depth = getDepth(root);
        ans.resize(depth);
        post_traverse(root, 0, ans);
        return ans;
    }
    int getDepth(TreeNode* cur) {
        if(cur == NULL)
            return 0;
        int l = getDepth(cur->left);
        int r = getDepth(cur->right);
        return std::max(l,r)+1;
    }
    void post_traverse(TreeNode* cur, int d, vector<vector<int>>& ans) {
        // cur != NULL
        if(cur) {
            post_traverse(cur->left, d+1,ans); //L
            post_traverse(cur->right,d+1,ans); //R
            // V
            ans[d].push_back(cur->val);
        }
        return;
    }
};