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
        利用BST的inorder traverse就是印出sorted array這個property
        當traverse到第k個就把它存為答案
    */
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int count = k;
        DFS(root, res, count);
        return res;
    }
private:
    void DFS(TreeNode* cur, int&res, int& count) {
        if(cur->left) DFS(cur->left, res, count);
        count--;
        if(!count) {
            res = cur->val;
            return;
        }
        if(cur->right) DFS(cur->right, res, count);
    }
};