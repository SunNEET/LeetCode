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
        BFS + queue
        根據queue的大小，先init好這一層的vector的size，然後就可以任意從前面或後面填val了
        Time: O(N)
        Space: O(N)
    */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        bool toleft = false;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            int cnt = 0;
            vector<int> cur(sz);
            while(sz--) {
                TreeNode* t = q.front(); q.pop();
                if(!toleft) {
                    cur[cnt++] = t->val;
                } else {
                    cur[sz] = t->val;
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(cur); 
            toleft = !toleft;
        }
        return res;
    }
};