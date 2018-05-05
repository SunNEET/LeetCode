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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        int d = depth(root);
        ans.resize(d);
        printf("%d\n",d);
        traverse(root, d-1, ans);
        return ans;
    }
    int depth(TreeNode* cur) {
        if(!cur)
            return 0;
        int l = depth(cur->left);
        int r = depth(cur->right);
        return max(l,r)+1;
    }
    void traverse(TreeNode* cur, int d, vector<vector<int>>& ans) {
        if(cur){
            traverse(cur->left,d-1,ans); //L
            traverse(cur->right,d-1,ans);//R
            ans[d].push_back(cur->val); //V
        }
    }
};