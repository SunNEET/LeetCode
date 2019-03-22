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
        如果A跟B一樣長的話，那first round這兩個就會碰到了
        如果不一樣長，比方說A比較短，那當他已經到底了，就把他接到B的起點
        當B也到底了就把它接到A的起點，這樣做就抵銷了兩邊一開始的差距
        ex: example2
        a到底走了 3 + 2 
        b到底走了 1 + 2
        兩邊要走到一樣的步數就是去走對方的起點
        =>  a: 3 + 2 + 1
            b: 1 + 2 + 3
        坑點：為了處理兩條list沒有 collision 的情況
        必須用 cur_a/cur_b 已經到 NULL 了來當作換list的條件
        否則他們會沒有一個能到達的共通點
    */
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;
        while(cur_a != cur_b) {
            cur_a = !cur_a ? headB : cur_a->next;
            cur_b = !cur_b ? headA : cur_b->next;
        }
        return cur_a;
    }
};