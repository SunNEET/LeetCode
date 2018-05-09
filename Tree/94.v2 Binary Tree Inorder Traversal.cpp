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
    // 前一個作法的改良, 多開一個hash來記錄左節點是不是訪問過了
    // 這樣就不會破壞tree結構了
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur;
        unordered_map<TreeNode*,bool> isVisited;
        while(!st.empty()) {
            cur = st.top();
            if(cur->left && !isVisited[cur->left]) {
                st.push(cur->left);
            } else {
                // L->V
                ans.push_back(cur->val);
                isVisited[cur] = true;
                st.pop();
                // V這時已經pop掉了
                // 所以就不用擔心之後會重複進入cur->right
                if(cur->right)
                    st.push(cur->right);
            }
        }
        return ans;
    }
};