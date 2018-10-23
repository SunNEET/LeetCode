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
    // 題目不好懂, 有個重要的條件是"右節點只會是葉子節點而且必須左邊有兄弟節點存在", 否則就是"empty"
    // flip 就是把這些右節點都接到左節點, 然後最左邊的節點成為新的頂點
    // 作法: DFS往左子樹遞回到底, 退出的時候再把左右子樹接起來
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* n_root;
        DFS(root, &n_root);
        return n_root;
    }
    
    void DFS(TreeNode* cur, TreeNode** pn_root) {
        if(cur->left) {
            DFS(cur->left, pn_root);
            // 要從V退出了, 將V的左節點的left接到V的右節點
            // V的左節點的right則接到V
            cur->left->left = cur->right;
            cur->left->right = cur;
            cur->left = NULL; // 重要, 目前的節點V也得把自己的pointer取消
            cur->right = NULL;
        } else {
            *pn_root = cur;
        }
        return;
    }
};