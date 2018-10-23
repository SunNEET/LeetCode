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
    // BST的性質, 右子樹value>左子樹value
public:
    TreeNode* convertBST(TreeNode* root) {
        int acc = 0;
        DFS(root, acc);
        return root;
    }
    
    void DFS(TreeNode* cur, int& acc) {
        
        if(!cur) return;
        DFS(cur->right, acc);
        acc += cur->val;
        cur->val = acc;
        DFS(cur->left, acc);
        return;
    }
};