/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 1->2->3->4, k = 3
    // 2->3->4->1
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode* tmp = head;
        int len = 1;
        while(tmp->next) {
            len++;
            tmp = tmp->next;
        }
        tmp->next = head; // make it a circular linked list
        tmp = head;
        k %= len;
        int cnt = len-k-1; // do len-k times it will stop at the newhead
                           // but we want to stop at the node just before the newhead,
                           // so we can make it connect to NULL
        ListNode* newhead;
        while(cnt--) tmp = tmp->next;
        newhead = tmp->next;
        tmp->next = NULL;
        return newhead;
    }
};