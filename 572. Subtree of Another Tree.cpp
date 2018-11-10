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
        Solution: 用 DFS 搜 s, 搜到跟t的root一樣的就丟到 isSametree 判斷
        
        Time Complexity: Say s has n of nodes, and t has m of nodes.
        The worst case of isSametree function takes O(m) time. (happens when it successfully traverse the entire tree t)
        The worst case of DFS would be O(n*m), because we might have many nodes' root that are same with t's,
        we'll have to use isSametree() at the each one

        corner case: 要考慮t的root出現在s的許多地方
        ([1,1] [1]) 從s的第一個1判斷 isSametree 會return false
        所以不能直接看到一樣的node就回傳 isSametree 的結果
        左右子樹能否找到也要一起判斷
    */
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return DFS(s,t);
    }
    
    bool DFS(TreeNode* s, TreeNode* t) {
        bool same = false;
        if(!s) return false;
        if(s->val == t->val) 
            same = isSametree(s,t);
        return same || DFS(s->left,t) || DFS(s->right,t);
    }
    
    bool isSametree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        // if(!s && t) return false;
        // if(s && !t) return false;
        if(!s || !t) return false;
        if(s->val == t->val)
            return isSametree(s->left,t->left)&&isSametree(s->right,t->right);
        else
            return false;
    }
};