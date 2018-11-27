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
        多了一個步驟的 linked list reverse
        
        Time Complexity: O(N)
    */
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(hasKNodes(cur, k)) {
            for(int i=0; i<k-1; i++) {
                ListNode* tmp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = tmp;
            }
            pre = cur;
            cur = pre->next;
        }
        return dummy->next;
    }
    
    bool hasKNodes(ListNode* cur, int k) {
        int cnt = 0;
        while(cur) {
            cnt++;
            if(cnt >= k) return true;
            cur = cur->next;
        }
        return false;
    }
};