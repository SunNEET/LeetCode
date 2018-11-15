/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    題目要設計一個Iterator的class，把 root 丟進去後，可以透過 int next() 返回下一個最小值，
    還有透過 hasNext() 判斷還有沒有下個最小值。
    Solution: 在 binary tree 上找下個最小值，其實就跟找 in-order traverse 下一個要 visit 的節點一樣。
    (因為 in-order traverse 訪問的 path 會是 a sorted sequence)
    所以這題其實就是做 in-order traverse 而已，但要用 stack 的做法，這樣才能保存當前的狀態。

    Time complexity: O(N)
    Edge cases: ?
*/
class BSTIterator {
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = myStack.top();
        myStack.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
    
    void pushAll(TreeNode* node) {
        while(node != NULL){
            myStack.push(node);
            node = node->left;
        }
    }
};
