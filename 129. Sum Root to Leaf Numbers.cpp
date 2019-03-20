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
        用 DFS 把當前的總和*10+cur->val 一路往下傳到葉子節點    
        Time:  O(N)
        Space: O(logN)~O(N), tree may degrade into a linked list
    */
public:
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
    int DFS(TreeNode* cur, int sum) {
        if (!cur) return 0;
        if (!cur->right && !cur->left) return sum*10 + cur->val;
        return DFS(cur->left, sum*10 + cur->val) + DFS(cur->right, sum*10 + cur->val);
    }
};