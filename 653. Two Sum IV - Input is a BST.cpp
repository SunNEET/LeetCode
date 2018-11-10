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
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        unordered_set<int> visited;
        return DFS(root,k,visited);
    }
    
    bool DFS(TreeNode* cur, const int& k, unordered_set<int>& visited) {
        if(!cur) return false;
        if(visited.count(k-cur->val)) 
            return true;
        visited.insert(cur->val); // IMPORTANT, place here below visited.count to prevent k = cur->val + cur->val
        return  DFS(cur->left,k,visited) || DFS(cur->right,k,visited);
    }
};