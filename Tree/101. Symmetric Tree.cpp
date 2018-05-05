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
    // DFS的解法,同時遞回兩邊的節點來比較他們的值
public:
    bool isSymmetric(TreeNode* root) {
        //root==NULL
        if(!root) return true;
        return helper(root->left,root->right);
    }
    bool helper(TreeNode* l, TreeNode* r) {
        
        // 兩邊都到NULL節點,有對稱所以回傳true
        if(!l && !r) return true;
        // a or b 只有其中一邊是NULL(上面先判斷都是NULL的情況了,所以這邊不會遇到),不對稱所以是false
        if(!l || !r) return false;
        // 要先判斷完是不是null才能來比值,不然會RTE
        if(l->val != r->val) return false;
        //對稱就是左子樹的左邊跟右子樹的右邊比較
        //和左子樹的右邊跟右子樹的左邊
        bool con1 = helper(l->left,r->right);
        bool con2 = helper(l->right,r->left);
        return con1&&con2;
    }
};