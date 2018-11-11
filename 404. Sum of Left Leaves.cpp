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
        solution: Traverse the tree and add the node value when it's a left leaves
        time complexity: O(V) # of vertexes
        edge case: [1,2,3,4,5], []
    */
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        DFS(root,sum);
        return sum;
    }
    void DFS(TreeNode* cur, int& sum) {
        if(cur->left) {
            if(!cur->left->left && !cur->left->right)
                sum += cur->left->val;
            DFS(cur->left,sum);
        }
        if(cur->right)
            DFS(cur->right,sum);
    }
};