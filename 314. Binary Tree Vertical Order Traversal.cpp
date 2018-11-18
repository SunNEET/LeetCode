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
        因為同個 level 裡的節點要滿足上到下，左到右的順序來存進 vector 裡，因此用 BFS 是最合適的。
        紀錄 vertical level 的方法就是 BFS 的同時維護一個變數 col 的 queue，這個 col 從 0 開始做，
        往左子樹移的時候就存 col-1，右子樹就 col+1。
        然後根據visit node的時候根據他的 col 來塞到對應的 vector (這可以用 map 做)
    */
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> qT;
        queue<int> qC;
        unordered_map<int,vector<int>> vLevel;
        qT.push(root);
        qC.push(0);
        int minC=0,maxC=0;
        while(!qT.empty()) {
            TreeNode* cur = qT.front();
            int col = qC.front();
            vLevel[col].push_back(cur->val);
            minC = min(minC,col);
            maxC = max(maxC,col);
            qT.pop();
            qC.pop();
            if(cur->left) {
                qT.push(cur->left);
                qC.push(col-1);
            }
            if(cur->right) {
                qT.push(cur->right);
                qC.push(col+1);
            }
        }
        
        for(int i=minC;i<=maxC;i++)
            res.push_back(vLevel[i]);
        return res;
    }
};