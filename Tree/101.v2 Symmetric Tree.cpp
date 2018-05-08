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
    // BFS解法
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        queue<TreeNode*> qL,qR;
        qL.push(l);
        qR.push(r); 
        
        // 這邊是||或&&其實沒影響,因為能順利對稱到最後的話,兩邊的數量必定一樣
        // 而會造成兩邊q長度不同的情況,就是其中一側左右節點有缺,而另一側沒缺
        // 不過這在!l || !r就會直接處理掉然後回傳答案了,所以才不需要去理他
        while(!qL.empty() || !qR.empty()) {
            l = qL.front();
            r = qR.front();
            qL.pop(); qR.pop();
            // 這邊跟DFS作法一樣,先看是否都NULL對稱,再看是否有單邊NULL,最後再比val
            // 都是NULL,他們沒有左右子節點,直接continue
            if(!l && !r) continue;
            // 不對稱, 直接回傳false結束
            if(!l || !r) return false;
            // 同上
            if(l->val != r->val) return false;
            
            qL.push(l->left);
            qR.push(r->right);
            qL.push(l->right);
            qR.push(r->left);
        }
        return true;
    }
};