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
    int maxDepth(TreeNode* root) {
        return DFS(root);
    }
    int DFS(TreeNode* cur) {
        if(!cur) return 0;
        return max(DFS(cur->left),DFS(cur->right))+1;
    }
};