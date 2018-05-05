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
    // 跟前一題基本一樣, 前序是最前面的會是根節點, 反過來而已
    unordered_map<int,int> hash;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) {
            hash[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int s0, int e0, vector<int>& inorder, int s1, int e1) {
        //已到NULL節點
        if(s0>e0||s1>e1) {
            return NULL;
        }
        // 這個區段中,前序的開頭就是區段的根節點
        TreeNode* root = new TreeNode(preorder[s0]);
        int mid = hash[preorder[s0]];
        int num = mid - s1;
        root->left = build(preorder,s0+1,s0+num,inorder,s1,mid-1);
        root->right = build(preorder,s0+num+1,e0,inorder,mid+1,e1);
        return root;
    }
};