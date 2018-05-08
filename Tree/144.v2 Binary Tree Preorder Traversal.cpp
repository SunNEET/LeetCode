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
    // 用stack做做看
    // 概念跟deque差不多,只是LR押入順序要弄對
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> sT;
        sT.push(root);
        TreeNode* cur;
        while(!sT.empty()) {
            cur = sT.top();
            sT.pop();
            ans.push_back(cur->val);
            if(cur->right) sT.push(cur->right);
            if(cur->left) sT.push(cur->left);
        }
        return ans;
    }
};