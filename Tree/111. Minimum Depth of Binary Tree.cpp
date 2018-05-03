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
    int Min = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        traverse(root,1);
        return Min;
    }
    void traverse(TreeNode* cur, int d) {
        if(cur) {
            if(!cur->left && !cur->right)
                Min = min(Min,d);
            traverse(cur->left, d+1);
            traverse(cur->right, d+1);
        }
    }
};