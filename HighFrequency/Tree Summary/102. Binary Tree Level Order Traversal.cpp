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
    // 用 BFS 來遍歷 tree，分層時機的判斷是塞一個NULL進queue
    // 當我們 pop 到 NULL的時候表示這層已經結束了，同時推入新的NULL，來作為下一層的標記
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // 第一層結束的標記
        vector<vector<int>> ans;
        vector<int> curLv;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(!cur) {
                ans.push_back(curLv);
                curLv.clear();
                if(q.size()>0) // 特判排除葉子節點，因為最後一層不會推節點，所以q會是0，不用再塞NULL讓BFS判斷下一層
                    q.push(NULL);
            } else {
                curLv.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return ans;
    }
};