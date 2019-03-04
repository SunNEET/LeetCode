/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /* 原理跟 remove 指定 val 時 (LC 203) 一樣，用 cur->next 當基準，而且重接完 next 以後不能馬上 move 到 next，避免踩到要被移除(重複)的點上 */
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = &dummy;
        while(cur) {
            if(cur->next && cur->next->next && cur->next->val == cur->next->next->val) {
                int duplicate = cur->next->val;
                ListNode *runner = cur;
                while(runner->next && runner->next->val == duplicate) runner = runner->next;
                cur->next = runner->next;
            } else {
                cur = cur->next;                
            } 
        }
        return dummy.next;
    }
};