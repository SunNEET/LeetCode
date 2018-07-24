/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1->2->3->4->5 k=2
// 4->5->1->2->3->NULL

// 1->2->3->NULL k=2
// 2->3->1->NULL

// 1->2
// 1 k=1

// 直接做,沒優化的版本
// 解題關鍵在於算list長度時要順便保留最後一個節點,然後將這個節點接回起點
// 之後根據長度和k找出會被接到null的新終點
// 先把解答(dummy)的起點接到新終點的下個點
// 然後再把新終點去接NULL

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int len = 0;
        ListNode* cur = head;
        ListNode* tail = dummy;
        while(cur){
            tail = cur;
            cur = cur->next;
            len++;
        }
        tail->next = head;
        
        k %= len;
        cur = head;
        int target = len-k;//找新起點的前一個節點,把他接到NULL
        for(int i=1;i<target;i++)
            cur = cur->next;
        dummy->next = cur->next;
        cur->next = NULL;
        return dummy->next;
    }
};