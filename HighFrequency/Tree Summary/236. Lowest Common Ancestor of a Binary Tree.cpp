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
    // 從根節點往左右兩子樹遞回找 p 跟 q，走到底還找不到的就讓他自然回傳NULL，往下有遇到 p 或 q 的就直接回傳
    // (1)如果某節點的左邊或右邊其中一邊回來的結果是null，另一邊有p,q，那就繼續回傳p,q
    // 都是null的話自然就回傳null(表示p,q不在這邊的子樹裡)
    // 這個判斷寫在遞回最下方 l ? l:r
    // (2)如果某節點的左右兩側都有結果回來，代表這個 root 就是LCA
    // (3)還有一種情況是，p,q 本身就是 LCA 的時候，不過這會在遇到p,q就直接回傳的判斷裡一起處理
    // 畢竟遇到p或q其中一個就不會繼續往下走了，如果p或q在另一個人的子樹底下，那就只有作為root的那個會被一路傳回頂端的
    // 而他就會是答案了
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return DFS(root,p,q);
    }
    TreeNode* DFS(TreeNode* cur, TreeNode*& p, TreeNode*& q) {
        if( !cur || cur==p || cur==q )
            return cur;
        TreeNode* left = DFS(cur->left,p,q);
        TreeNode* right = DFS(cur->right,p,q);
        if(left && right)
            return cur;
        return left ? left:right; // 兩邊都是null的話就會由right回傳null，一樣的意思
    }
};