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
        善用三元運算子 t1?t1->val:0 的這種形式來 new node就好
        這樣有重疊的話自然就是兩個相加，已經是null的那個就會被當成0
        兩邊都null就return null
    */
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return NULL;
        
        TreeNode* merge_node = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
        merge_node->left = mergeTrees((t1 ? t1->left : NULL), (t2 ? t2->left : NULL));
        merge_node->right = mergeTrees((t1 ? t1->right : NULL), (t2 ? t2->right : NULL));
        return merge_node;
    }
};