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
    // 直覺想到的作法, 就是不同路線都遍歷一遍, 然後把結果存到set
    // 之後直接查set裡有沒有這個值就好
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        set<int> si;
        dfs(root,si,0);
        return si.find(sum)!=si.end();
    }
    void dfs(TreeNode* cur, set<int>& si, int sum) {
        if(cur) {
            sum += cur->val;
            // 到葉子就把答案存進去
            if(!cur->left && !cur->right){
                si.insert(sum);
                return;
            }
            dfs(cur->left, si,sum);
            dfs(cur->right,si,sum);
        }
    }
};
