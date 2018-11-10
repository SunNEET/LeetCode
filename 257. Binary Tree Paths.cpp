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
        Solution: Just using DFS to traverse the tree, store the path when reaching a leaf node.
        Time Complexity: O(N), says N is the number of the root's nodes
        Edge Case: empty root
    */
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> res;
        string str="";
        str += to_string(root->val);
        DFS(root, res, str);
        return res;
    }
    void DFS(TreeNode* cur, vector<string>& res, string str) {
        if(!cur->left && !cur->right){
            res.push_back(str);
            return;
        }
        if(cur->left)  DFS(cur->left, res, str + "->" + to_string(cur->left->val));
        if(cur->right) DFS(cur->right, res, str + "->" + to_string(cur->right->val));
        return;
    }
};

class Solution {
public:
    // edge case: (1) root 有 null 
    // (2) 想用 call by reference 省空間，但pop_back的時候要注意->是兩個字元，且數字超過一位數也要多pop幾次
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> res;
        string str="";
        str += to_string(root->val);
        DFS(root, res, str);
        return res;
    }
    void DFS(TreeNode* cur, vector<string>& res, string& str) {
        if(!cur->left && !cur->right){
            res.push_back(str);
            return;
        }
        str += "->";
        if(cur->left) {
            str += to_string(cur->left->val);
            DFS(cur->left,res,str);
            for(int i=0;i<to_string(cur->left->val).length();i++) str.pop_back();
        }
        if(cur->right) {
            str += to_string(cur->right->val);
            DFS(cur->right,res,str);
            for(int i=0;i<to_string(cur->right->val).length();i++) str.pop_back();
        }
        str.pop_back();
        str.pop_back();
        return;
    }
};