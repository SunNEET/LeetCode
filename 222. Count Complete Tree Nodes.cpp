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
        要判斷節點的數量，我只要知道最後一個葉子節點在哪就可以遞回處理
        *善用 complete BT 的性質，除了葉子節點的那層以外，每層都是滿的，並且葉子節點都會往左靠
        
        如果左子樹的高度 = 右子樹的高度，表示最後一個葉子節點會在右子樹，所以左子樹必定是滿的
        令h為整顆樹的高度，可以得出節點數量 = 2^(h-1) + 1 + 右子樹的節點數量，再來就遞歸地移到右子樹做處理
        如果左子樹的高度 = 右子樹的高度 + 1，表示最後一個葉子節點會在左子樹，所以右子樹必定是滿的(只是少一層)
        所以節點數量就是 = 左子樹的節點數量 + 1 + 2^(h-2)，然後遞歸到左子樹進行處理
    */
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == rh) return pow(2,lh)-1 + 1 + countNodes(root->right);
        else return countNodes(root->left) + 1 + pow(2,rh)-1;
    }
    int height(TreeNode* root) {
        if(!root) return 0;
        return height(root->left) + 1;
    }
};
class Solution {
    /*
        DFS 掃過
        Time: O(N), TLE!!!
    */
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        DFS(root, cnt);
        return cnt;
    }
    
    void DFS(TreeNode* root, int& cnt) {
        if(!root) return;
        cnt++;
        DFS(root->left, cnt);
        DFS(root->right, cnt);
    }
};