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
    int depth = 1;
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        post_traverse(root,depth);
        return depth; 
    }
    void post_traverse(TreeNode* cur, int d) {
        if(cur) {  // cur!=NULL
            post_traverse(cur->left,d+1);   // L
            post_traverse(cur->right,d+1);  // R
                                            // V
            depth = max(depth,d);
        }
        return;
    }
};
