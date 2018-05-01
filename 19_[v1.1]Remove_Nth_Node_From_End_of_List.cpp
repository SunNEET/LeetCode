/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* pass兩次 */
/* 使用dummy node的方法減少特判*/ 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* tmp = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* tmp = dummy;
        int len = 0;
        while(tmp!=NULL) {
            tmp = tmp->next;
            len++;
        }
        len--; //去掉dummy
        int target = len-n+1;
        tmp = dummy;
        int cur = 0;
        while(tmp!=NULL) {
            if (cur==target-1)
                tmp->next = tmp->next->next;
            tmp = tmp->next;
            cur++;
        }
        return dummy->next;
    }
};