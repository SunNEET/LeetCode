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
    // DFS
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p,q);
    }
    // 兩邊一起traverse,值不同就回傳false
    bool helper(TreeNode* p, TreeNode* q) {
        // 都先判斷NULL,避免爆炸
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return helper(p->left,q->left) && helper(p->right,q->right);
    }
};