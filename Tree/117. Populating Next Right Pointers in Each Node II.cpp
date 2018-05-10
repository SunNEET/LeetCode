/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    // 概念跟上一題很像, 只是這次因為不能保證左右子樹必定存在
    // 所以next接起來的時間點不一樣
    // 之前是從root往左右看的時候就可以直接串
    // 現在是往左右子節點看,有子節點的話就先把他設成last
    // 在出現下一個子節點的時候就把剛剛的last接到這個節點 類推
    
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* cur = root;
        TreeLinkNode* first = NULL;
        TreeLinkNode* last = NULL;
        while(cur) {
            // 找下一層的第一個節點, 讓cur右移到底後接過去用的
            if(!first) {
                if(cur->left){
                    first = cur->left;
                } else {
                    first = cur->right;
                }
            }
            if(cur->left) {
                if(last) {
                    last->next = cur->left;
                }
                last = cur->left;
            }
            if(cur->right) {
                if(last) {
                    last->next = cur->right;
                }
                last = cur->right;
            }
            if(cur->next) {
                cur = cur->next;
            } else {
                cur = first;
                first = NULL;
                last = NULL;
            }
        }
    }
};