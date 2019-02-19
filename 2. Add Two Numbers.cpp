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
        To simplify the logic inside while loop, I use a dummy node.
        Later I'll make its next connect to the beginning of the sum.

        To address a condition that two linked list lengths are different,
        I'll check if they already arrived the end of the list before
        adding its value to sum or moving to next node.

        Time: O(max(|l1|,|l2|))
        Space: O(1)
    */
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return dummy.next;
    }
};