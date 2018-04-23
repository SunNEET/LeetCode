/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 遞迴版
// 如果head下一個節點的val跟目前head起點的val值不相同
// 那就可以將問題拆成: head->(一串) ==> head->(head_2->(一串)) ==> ... 類推
// 終止條件就是找到最後一個節點(他的下一個節點是NULL)為止

// 但如果相同,那這些包括head起點在內的節點,就都不能保留
// 一路往下找到不同的那個節點為止, 用內個節點作為新起點來繼續拆解問題
// ex: 1->2->2->2->4->5 ==> 1->(2->2->2->4->5->6->6->7) ==> 1->(4->(5->6->6->7)) .... 類推
//                              x  x  x  ＾        
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 前面的節點持續重複到尾巴的話, 就會造成傳進來的是NULL(找不到值不同的新起點)
        if (!head) 
            return NULL;
        // 已到末節點, 不會有值跟NULL重複, 所以直接回傳
        if (!head->next)
            return head;
        ListNode* nxt = head->next;
        int val = head->val;
        if(nxt!=val){
            head->next = deleteDuplicates(nxt);
            return head;
        } else {
            //找到沒有重複的group起點為止
            while(nxt && nxt->val==val)
                nxt = nxt->next;
            return deleteDuplicates(nxt);
        }
    }
};










