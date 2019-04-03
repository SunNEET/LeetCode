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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        DFS(head, &dummy, n, n);
        return dummy.next;
    }
private:
    void DFS(ListNode* cur, ListNode* pre, const int& n, int& counter) {
        if(!cur) return;
        DFS(cur->next, cur , n, counter);
        counter--;
        if(!counter) {
            pre->next = cur->next;
        }
    }
};