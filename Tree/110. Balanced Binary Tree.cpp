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
    // 用DFS掃, 掃到NULL回傳0
    // 樹中的"每個"節點都必須滿足平衡的條件(|lsize-rsize|<=1)
    // 所以往下掃的時候, 每個節點都必須比較自己左右子樹的高度差距
    // 從下往上遞歸的過程中如果有節點已經不符合這個要求了, 那表示整顆樹都不滿足了
    // 回傳值代表的是高度, 但為了判斷是否有節點已經out, 所以加入-1這要素(很厲害的技巧)
    // 當|lsize-rsize|>1的時候表示這個節點延伸出去不平衡, 而如果子節點傳回-1的話
    // 不論另一側的高度是多少, 都會先判斷到是否為-1, 也就繼續把整顆樹不合格的狀態往上傳了
    
    // *這樣就能在一邊回傳正常高度的情況下, 像是回傳bool值一樣淘汰不行的部分*
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* cur) {
        // NULL節點, 回傳0
        if(!cur) return 0;
        
        int left_h = dfs(cur->left);
        // 左邊已經不行了,直接回傳-1
        if(left_h == -1) return -1;
        int right_h = dfs(cur->right);
         // 右邊不行了,同上
        if(right_h == -1) return -1;
        // 兩邊都有正常的回傳高度, 但算出來相差超過1, 開始不行ㄌ
        if(abs(left_h-right_h)>1) return -1;
        
        return max(left_h,right_h)+1;
    }
};
