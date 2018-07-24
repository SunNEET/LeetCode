/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /* pass兩次*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int len = 0;
        while(tmp!=NULL) {
            tmp = tmp->next;
            len++;
        }
        //特判,移除會變空的
        if (len==1)
            return NULL;
        int target = len-n+1;
        //特判,砍頭
        if (target == 1)
            return head->next;
        tmp = head;
        int cur = 1;
        while(tmp!=NULL) {
            if (cur==target-1)
                tmp->next = tmp->next->next;
            tmp = tmp->next;
            cur++;
        }
        return head;
    }
};