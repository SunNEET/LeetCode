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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        int v1=0,v2=0;
        ListNode* l1next = NULL;
        ListNode* l2next = NULL;
        //任一個list還有節點就繼續做
        while(l1!=NULL || l2!=NULL){
            //沒節點(NULL)的就給極大值
            v1 = (l1!=NULL) ? l1->val : INT_MAX;
            v2 = (l2!=NULL) ? l2->val : INT_MAX;
            //防呆,避免對NULL用->next
            l1next = (l1!=NULL) ? l1->next : NULL;
            l2next = (l2!=NULL) ? l2->next : NULL;
            //先往下個新節點移動再assign,避免多出來的節點
            if (v1 < v2) {
                cur->next = new ListNode(0);
                cur = cur->next;
                cur->val = v1;
                l1 = (l1next!=NULL) ? l1next : NULL;
            }
            else {
                cur->next = new ListNode(0);
                cur = cur->next;
                cur->val = v2;
                l2 = (l2next!=NULL) ? l2next : NULL;
            }
        }
        return res->next;
    }
};