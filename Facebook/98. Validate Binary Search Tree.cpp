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
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return DFS(root, &pre);
    }
    
    bool DFS(TreeNode* cur, TreeNode** pprev) { 
        // Here I use a pointer to points to a Treenode pointer. 
        // This helps me keep track of the current maximum value when DFS is traversing the tree
        if(!cur) return true;
        // LVR
        bool l = DFS(cur->left, pprev);
        // We simply check if the value of the current visited node
        // is greater than that of the last visited node.
        // The value of the last visited node is actually an current maximum value, 
        // since we are traversing in in-order way, and its visiting order produce an sorted array.
        
        // After a node's left tree finish visit, it's going to visit the node
        // At this time, we determine if a tree is valid.
        // If it isn't, then we return false. Otherwise we visit this node and set prev to cur,
        // and move to right subtree.
        if( (*pprev)!=NULL &&  cur->val <= (*pprev)->val)
            return false;
        *pprev = cur;
        bool r = DFS(cur->right, pprev);
        
        return l && r; // if both left and right subtree are valid, we'll return true.
    }
};