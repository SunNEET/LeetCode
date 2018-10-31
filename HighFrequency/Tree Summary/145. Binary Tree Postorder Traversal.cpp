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
    vector<int> postorderTraversal(TreeNode* root) {
        deque<int> res;
        vector<int> ans;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(cur || !st.empty()) {
            if(cur) {
                res.push_front(cur->val);
                st.push(cur);
                cur = cur->right;
            } else {
                // Already reached the end of right side
                cur = st.top();
                st.pop();
                cur = cur->left;
            }
        }
        for(int i=0;i<res.size();i++) ans.push_back(res[i]);
        return ans;
    }
};