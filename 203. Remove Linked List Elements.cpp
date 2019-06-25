/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /* 
        用 cur->next->val 來檢查 val，就能跳過他連到下一個
        
        坑點：更新 next 不能馬上往 next 移動，因為可能遇到要連續移除的狀況, e.g. 1 -> 1 -> 1, val = 1
        如果移完就移動會導致 cur 所在的那個 1 移不掉，所以每次接完 next 就是繼續 loop，確定下一個不用移除我們才 move 到 next
        坑點2(06/24/2019)：回傳值要 dummy.next，因為head有可能是要被移掉的元素。
    */
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = &dummy;
        while(cur) {
            if(cur->next && cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};