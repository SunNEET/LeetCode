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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> todo;
        TreeNode* cur = root;
        vector<int> ans;
        while(cur || !todo.empty()) {
            if(cur) {
                todo.push(cur);
                cur = cur->left;
            } else {
                // null node, push its parent into ans
                cur = todo.top();
                todo.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};