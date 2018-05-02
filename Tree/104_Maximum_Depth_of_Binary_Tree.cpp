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
	// 用後序遍歷(LRV)走一次，維護全域depth
  // edge case: root是空的,return 0
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
