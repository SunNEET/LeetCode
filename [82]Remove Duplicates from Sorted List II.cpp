/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//不考慮時間複雜度
//直接掃一遍找重複的
//在重掃一遍把重複的跳過
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        map<int,int> cnt;
        ListNode* cur = head;
        while(cur){
            cnt[cur->val]++;
            cur = cur->next;
        }
        cur = head;
        ListNode* pre = dummy;
        while(cur){
            if(cnt[cur->val] <= 1){
                pre->next = cur;
                pre = pre->next;
            }
            cur = cur->next;
        }
        pre->next = NULL;
        return dummy->next;
    }
};