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
    // 這題直接枚舉就可以過了, 但也可以用DP優化
    // 先寫簡單枚舉的版本
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return generateTree(1,n);
    }
    
    vector<TreeNode *> generateTree(int from, int to) {
        vector<TreeNode *> ret;
        if(to - from < 0) ret.push_back(0);
        if(to - from == 0) ret.push_back(new TreeNode(from));
        if(to - from > 0)
        {
            for(int i=from; i<=to; i++)
            {
                vector<TreeNode *> l = generateTree(from, i-1);
                vector<TreeNode *> r = generateTree(i+1, to);

                for(int j=0; j<l.size(); j++)
                {
                    for(int k=0; k<r.size(); k++)
                    {
                        TreeNode * h = new TreeNode (i);
                        h->left = l[j];
                        h->right = r[k];
                        ret.push_back(h);
                    }
                }
            }
        }
        return ret;
    }
};

