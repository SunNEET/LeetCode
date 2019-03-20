class Solution {
    /*
        Iterative, BFS
    */
public:
    int maxDepth(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int sz = q.size(), res = 0;
        while(!q.empty()) {
            res++;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            sz = q.size();
        }
        return res;
    }
};

class Solution {
    /*
        Recursion, DFS
    */
public:
    int maxDepth(TreeNode* root) {
        return DFS(root);
    }
    
    int DFS(TreeNode* cur) {
        if(!cur) return 0;
        return max(DFS(cur->left), DFS(cur->right))+1;
    }
};