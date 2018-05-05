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
    // 改用動態新增層數的方式, 就不用先跑一次深度了
    // 這題的直覺作法是先照先前一樣的方法掃一次
    // 事後再reverse
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root,0,ans);
        for(int i=0;i<ans.size();i++) {
            if(i&1)
                reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
    void traverse(TreeNode* cur, int d, vector<vector<int>>& ans) {
        if(ans.size()<d+1 && cur!=NULL)
            ans.push_back(vector<int>());
        if(cur) {
            traverse(cur->left,d+1,ans);
            traverse(cur->right,d+1,ans);
            ans[d].push_back(cur->val);
        }
        return ;
    }
};