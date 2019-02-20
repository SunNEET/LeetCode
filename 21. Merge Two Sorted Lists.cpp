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
        用dummy.next指向新的開頭, tail = &dummy
        l1 l2 比較哪個比較小就接到哪個
    */
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 != NULL || l2 != NULL) {
            if(l1 == NULL || (l2!=NULL && l2->val < l1->val)){
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};