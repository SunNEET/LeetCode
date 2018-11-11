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
        Solution: Using BFS. Whenever we finish traversing a level, calculate its average.
        A tips here is using NULL to indicate end of a level.

        Time complexity: Suppose Tree has n numbers of nodes => O(n)

        Edge cases: Note that value of a node might be very big. To avoid overflow, use a larger
        numerous type when declare "sum".
    */
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> qT;
        qT.push(root);
        qT.push(NULL);
        double sum = 0.0;
        int cnt = 0;
        while(!qT.empty()) {
            TreeNode* cur = qT.front();
            qT.pop();
            if(cur == NULL) {
                res.push_back(sum/cnt);
                sum = 0;
                cnt = 0;
                if(!qT.empty())
                    qT.push(NULL);
            } else {
                sum += cur->val;
                cnt++;
                if(cur->left) qT.push(cur->left);
                if(cur->right) qT.push(cur->right);
            }
        }
        return res;
    }
};