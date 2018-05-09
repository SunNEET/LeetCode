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
    // 第三種方法最好, 不仰賴stack來做左右節點的移動
    // 直接指向下一個節點, stack只用來記錄根節點
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty()) {
            // 一直往左節點L移動
            // 這邊是移動到null才停,而不是沒左節點就停
            if(cur) {
                // 用來紀錄parent
                st.push(cur);
                cur = cur->left;
            } else {
                // 這個else同時處理兩種情況
                // 一個是進到左邊的null節點
                // 代表parent該進答案了
                // 因為上面都是先往L移動, L已經沒有了就回到V(L->V)
                // 並把V塞進答案裡, 接著就該往R移動(V->R)
                // 另一個自然是進到右邊的null
                // 由於剛剛parent塞進答案並且被pop掉了
                // 現在拿的parent其實是parent的parent(爺爺)
                // 這樣就可以一直往上推, 而不會無限loop了
                TreeNode* parent = st.top();
                st.pop();
                ans.push_back(parent->val);
                cur = parent->right;
            }
        }
        return ans;
    }
};