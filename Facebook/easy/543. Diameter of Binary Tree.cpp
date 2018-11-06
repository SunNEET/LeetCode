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
    int diameterOfBinaryTree(TreeNode* root) {
        int MAX = 0;
        DFS(root, MAX);
    
        return MAX;
    }
    int DFS(TreeNode* cur, int& MAX) {
        if(!cur) return 0;
        
        int l = DFS(cur->left, MAX);
        int r = DFS(cur->right, MAX);
        // It's possible that the longest path doesn't pass by the top-most root, but in the subtree
        // So in addition to return a greater value of subtree, we should also keep track of the current
        // maximum value by adding up the height of both sides
        MAX = max(MAX,l+r);
        return max(l,r)+1;
    }
};