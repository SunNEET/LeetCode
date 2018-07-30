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
    // 兩邊DFS下去, 每次回到V時比較左右兩側的深度, 如果超過1就一路回傳-1
    // 否則就回傳 最大的深度+1
public:
    bool isBalanced(TreeNode* root) {
        return DFS(root)!=(-1)?true:false;
    }
    int DFS(TreeNode* cur) {
        // 終止條件
        if(!cur) return 0;
        int lf = DFS(cur->left); 
        if(lf==-1) return -1;
        int rt = DFS(cur->right);
        if(rt==-1) return -1;
        if(abs(lf-rt)>1) return -1;
        return std::max(lf,rt)+1;
    }
};