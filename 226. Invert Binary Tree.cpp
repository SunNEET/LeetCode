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
    /*
        將root->left去接反轉後的right
        將root->right去接反轉後的left
    */
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};