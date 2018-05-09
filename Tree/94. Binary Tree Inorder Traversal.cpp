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
    // 比較直覺但不好的方法, 會破壞整顆tree的連結
    // 這個作法巧妙的地方在於不像前一題的作法
    // 拿到根節點->塞進答案->pop掉->塞左右子樹這麼直觀
    
    // 而是一直把原本的根節點塞進stack裡但不pop掉
    // 藉此讓根節點一直往左節點移動, 同時保留原本的根節點
    // 當左節點沒辦法繼續下去了(可能是葉子或是只有左邊是null)
    // 這個左節點(L)就變成根節點(V)本身,這時候就可以把他輸出然後pop掉了
    // 要注意他還有沒有右節點(R),有的話就先塞stack
    // 做完R延伸出的那坨後就回到stack裡存到上一層V, 以此類推了
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur;
        while(!st.empty()) {
            cur = st.top();
            // 只有要有左節點就一直push進stack裡, 然後把自己跟左節點的link弄掉
            // 這樣子往回處理的時候才不會又進去if(cur->left)的判斷裡
            if(cur->left) {
                st.push(cur->left);
                cur->left = NULL;
            } else {
                // 沒有L了(或已經完成了),輸出自己(根節點V), pop掉,然後處理右節點
                ans.push_back(cur->val);
                st.pop();
                if(cur->right)
                    st.push(cur->right);
            }
        }
        return ans;
    }
};