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
        老樣子的幾個點要注意：比較next的值之前先判斷是不是null，不是的話就把next接到next的next
        坑點1：不需要也不能用dummy node，不然遇到head開頭的value跟dummy node一樣就尷尬了(會連第一個值都刪光)
        這題只要求刪掉第二個開始的重複值，所以直接用head就可以了
    */
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur) {
            if(cur->next && cur->val == cur->next->val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};