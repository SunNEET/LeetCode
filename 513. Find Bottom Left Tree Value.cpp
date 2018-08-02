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
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        int maxD=-1;
        dfs(root,0,ans,maxD);
        return ans;
    }
    // 簡單的DFS掃過去, 因為都是先往L走在往R走, 總之第一個位於更下一層的node就會是那層最左邊的node
    void dfs(TreeNode* cur, int d, int& ans, int& maxD) {
        if(!cur)
            return;
        dfs(cur->left,d+1,ans,maxD);
        dfs(cur->right,d+1,ans,maxD);
        if(d > maxD) {
            maxD = d;
            ans = cur->val;
        }
        return;
    }
};