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
    // 利用 BST 的性質來遞回解
    // (1) cur->left->val < cur->val < cur->right->val
    // (2) 要成為p跟q的祖先意味著cur->val會介於他們之間
    // 依照這兩個性質就可以解了
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};