/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    // 主要思路: 如果一個節點是根節點的左子樹, 那麼他的next就會是根節點的右子樹
    // 如果他是右子樹, 那他的next就是根節點的next的左子樹
    // 
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        TreeLinkNode* cur = root;
        TreeLinkNode* first = NULL;
        // 一層一層往下處理
        while(cur) {
            //紀錄下一層第一個左子樹
            if(!first) {
                first = cur->left;
            }
            // 如果有左子樹, 那麼next就是根節點的右子樹
            if(cur->left) {
                cur->left->next = cur->right;
            } else {
                //到葉子節點,可以結束了, 因為這一層的next在上一層就串好了
                break;
            }
            // 如果root有next, 再幫右子樹設定next
            // 所以最右邊的都不用接
            if(cur->next) {
                cur->right->next = cur->next->left;
                cur = cur->next;
            } else {
                // 轉到下一層
                cur = first;
                first = NULL;
            }
        }
    }
};