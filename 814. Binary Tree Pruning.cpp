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
        一路往下遞迴到葉子節點，當葉子節點是0的時候就return null，讓他的parent跟他失去連接
        如果一個parent的兩個子節點都沒了，自己又是0的話，自然也是 return null
        以上兩個條件可以寫在一起
        Time: O(N)
        Space: O(N)
    */
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left &&!root->right && root->val==0) return NULL;
        return root;
    }
};