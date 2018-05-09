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
    // 當遍歷到一個節點的時候，首先我們將右子樹壓棧，然後將左子樹壓棧。
    // 葉子節點就可以直接pop, 但根節點需要一個變量記錄上一次出棧的節點
    // 如果上一次出棧的節點是該根節點的左子樹或者右子樹, 那麼該根節點可以出棧
    // 否則這個根節點是新訪問的節點, 將右和左子樹分別壓棧
    // 簡單的說就是判斷現在是在往下還是往上走回去的過程碰到這個節點
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st; 
        TreeNode* pre = NULL;
        st.push(root);
        while(!st.empty()) {
            TreeNode* cur = st.top();
            // 分別判斷兩種能輸出答案並pop掉的情況
            // (1) 是葉子節點嗎? 
            // (2) 還是正從 葉子節點/剛剛退掉的節點 返回的節點?
            if((!cur->left && !cur->right) || (pre != NULL && (pre==cur->left||pre==cur->right))) {
                ans.push_back(cur->val);
                st.pop();
                pre = cur;
            }
            else {
                if(cur->right) {
                    st.push(cur->right);
                }
                if(cur->left) {
                    st.push(cur->left);
                }
            }
        }
        return ans;
    }
};