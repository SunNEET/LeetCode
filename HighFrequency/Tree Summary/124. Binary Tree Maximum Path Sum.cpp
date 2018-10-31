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
    // 從下往上算每個node從左右子樹上來到自己為止能累積的最大值
    // 比較最大長度 ans 有三種情況：
    // (1) 要回傳的，只傳其中一邊的累計值較大的+自己的節點值 (代表路往上走)
    // (2) 要回傳的，左右兩路加起來都是負的，而自己本身是正的 (代表路往上走，從這個點出發) (edge case!)
    // (3) 把左右跟自己都加起來 (代表路往左右走)，不回傳，只比較 ans
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        DFS(root, ans);
        return ans;
    }
    int DFS(TreeNode* cur, int& ans) {
        if(!cur)
            return 0;
        int left = DFS(cur->left, ans);
        int right = DFS(cur->right, ans);
        int ret = max(max(left,right)+cur->val, cur->val); //(1) + (3)
        ans = max(ans,ret); 
        ans = max(ans,left+right+cur->val); //(2)
        return ret;
    }
};