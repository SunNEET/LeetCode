/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// case1
// d->1->2->3->4-> NULL
//==loop 1==
// (d->1->2)
// d -> 2
// 2 -> 1
// d->2->1->3
//==loop 2==
// (1->3->4)
// ...

// case2
// d->1->NULL

// case3
// d->1->2->3
//==loop 1==
// d->2->1
//==loop 2==
// 1->3->null
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur && cur->next && cur->next->next){
            //nxt用來紀錄中間的node
            ListNode* nxt = cur->next;
            //把前面的節點,跳過中間接到後面
            //然後移動到後面內個節點
            cur->next = cur->next->next;
            cur = cur->next;
            //紀錄後面的節點原本指向的節點,也就是下一組的起點
            ListNode* nxt_head = (cur!=NULL) ? cur->next : NULL ;
            //把後面的節點接往中間
            //然後移動到中間內個節點
            cur->next = nxt;
            cur = cur->next;
            //從中間的節點接往下一組的起點
            cur->next = nxt_head;
            // cur = cur->next;
        }
        return dummy->next;
    }
};