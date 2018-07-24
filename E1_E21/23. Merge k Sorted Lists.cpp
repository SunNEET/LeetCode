/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 大抵上就是先對lists做分治
    // 1. 把lists裡的list先兩個湊成一組
    // 2. 在對這兩個lists做merge sort
    // 3. 重複步驟1
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return 0;
        if(k==1) return lists[0];
        return doMerge(lists, 0, (int)lists.size()-1);
    }
    // 對lists做分治
    ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
        // 這邊的分治終點並不用等到都只剩一個list再return
        // 當只剩兩個的時候, left+1==right就可以直接判斷出來
        // 這時就可以做mergesort然後return結果

        // l==r的情況是在剩下3個lists時, 再做divide才會出現
        // 因為這時r會只分到1個,l這邊有兩個
        if(left==right) 
            return lists[left];
        else if(left+1==right) 
            return merge2Lists(lists[left], lists[right]);
        
        ListNode* l1 = doMerge(lists, left, (left+right)/2);
        ListNode* l2 = doMerge(lists, (left+right)/2+1, right);
        return merge2Lists(l1, l2);
    }
    
    // merge sort 本身
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        
        if(l1==l2) return l1;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val > l2->val) return merge2Lists(l2, l1);
        ListNode* newl2 = new ListNode(0);
        newl2->next = l2;
        ListNode* p1 = l1;
        while (p1->next && newl2->next) {
            if (p1->next->val < newl2->next->val) {
                p1 = p1->next;
            } else {
                ListNode* temp = p1->next;
                p1->next = newl2->next;
                newl2->next = newl2->next->next;
                p1->next->next = temp;
                p1 = p1->next;
            }
        }
        if(!p1->next) 
            p1->next = newl2->next;
        delete newl2;
        return l1;
    }
};