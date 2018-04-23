/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*雙指標的做法*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //用一個node(dummy)在head之前, 可以直接處理各種特例(list node刪光, head node被刪掉)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int i=0;i<n+1;i++)
            first = first->next;
        while(first!=NULL){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};