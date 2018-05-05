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
    unordered_map<int,int> hash;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 先做好hash, 這樣等下從postorder知道根節點後, 就可以立刻找到inorder裡那個數字在哪
        for(int i=0;i<inorder.size();i++)
            hash[inorder[i]] = i;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    
    TreeNode* build(vector<int>& inorder, int s0, int e0, vector<int>& postorder, int s1, int e1) {
        // s0==e0||s1==e1 表示目前的位置是葉子，s0>e0||s1>e1就表示已經是葉子的兩個NULL了
        if (s0 > e0 || s1 > e1) {
            return NULL;
        }
        // 這個後序在他對應的區間裡, 最後一個值就是這個區間的根節點
        // 所以建出這個區間的root
        TreeNode* root = new TreeNode(postorder[e1]);
        // 根據根節點把中序序列分開成左右子樹
        int mid = hash[postorder[e1]];
        // 中序的左右子樹可以直接用[s0~mid-1],[mid+1,e0]切出區間
        // 但後序的要知道左右子數分別有幾個才能切
        // 而中序[s0~mid)的左子樹有幾個數, 就表示後序的左子樹會有幾個
        int num = mid-s0;
        root->left = build(inorder, s0, mid-1, postorder, s1, s1+num-1);
        root->right = build(inorder, mid+1, e0, postorder, s1+num, e1-1);
        return root;
    }

};