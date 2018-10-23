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
    // 节点的inorder successor 后继就是比给定节点大的所有节点中最小的那个
    // 也可以理解成 inorder 裡接在 p 後面下一個要訪問的點
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return NULL;
        TreeNode* suc = NULL; //先初始化suc成null, 如果p是最右邊的點那這個suc就會保持null
        // 從BST找到p的所在
        while(root!=NULL) {
            // p比root小, 所以往左移動
            // 比p大的最小點只有兩種可能, root本身或是往繼續p的右子樹找
            // 但只要p有右子樹存在的話, 那suc就一定在右子樹裡, 因為都比root小
            if(p->val < root->val) {
                suc = root;
                root = root->left;
            } else { // p >= root, 表示suc就是root右子樹裡的最小值, 往右移動
                root = root->right;
            }
        }
        return suc;
    }
};