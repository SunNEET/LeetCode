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
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> si;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy->next;
        ListNode* pre = dummy;
        while(cur){
            //已經有了,跳過這個node
            if(si.count(cur->val))
                pre->next = cur->next;
            else{
                si.insert(cur->val);
                pre = pre->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};