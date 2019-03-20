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
        two pointer 解決，一個指向<X，另一個指向>=X
        最後把<X 接到 >=X, >=X 的尾巴接到NULL
    */
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode dummy_g(0), dummy_l(0);
        ListNode* greater = &dummy_g, *less = &dummy_l;
        ListNode* cur = head;
        while(cur) {
            if(cur->val < x) {
                less->next = cur;
                less = less->next;
            } else {
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }
        less->next = dummy_g.next;
        greater->next = NULL;// 坑：因為是把原本的node拿來連，所以最後一個greater的node的next還連向原本list上的node
        return dummy_l.next;
    }
};