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
    // 前序遍歷就是按照VLR的順序來輸出
    // 不能用dfs的話, 直覺考慮是bfs, 但queue沒辦法維護我們想要的順序
    // 直覺考慮用deque, 一直從前面pop跟塞入新node就簡單了
    // 要注意:
    // 1. deque直接存取的複雜度是O(1)
    // 2. deque對起點和終點插入/移除的複雜度O(1)(amortized分析)
    // 3. 除此之外插入/移除的複雜度是O(N)
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        deque<TreeNode*> qT;
        qT.push_back(root);
        TreeNode* cur;
        while(!qT.empty()) {
            cur = qT.front();
            qT.pop_front();
            if(cur) {
                ans.push_back(cur->val);
                qT.push_front(cur->right);
                qT.push_front(cur->left);
            }
        }
        return ans;
    }
};