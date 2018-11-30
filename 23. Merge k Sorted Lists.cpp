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
        對 Lists 做分治，然後分別做 21. Merge Two Lists 的 merge就好了
    */
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        if(k==1) return lists[0];
        return  doMerge(lists, 0, k-1);
    }
    // 這邊的分治終點並不用等到都只剩一個list再return
    // 當只剩兩個的時候, left+1==right就可以直接判斷出來
    // 這時就可以做mergesort然後return結果
    // l==r的情況是在剩下3個lists時, 再做divide才會出現
    // 因為這時r會只分到1個,l這邊有兩個
    ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
        if(left == right)
            return lists[left];
        else if(left == right + 1)
            return mergeTwoLists(lists[left], lists[right]);
        ListNode* l1 = doMerge(lists, left, left+(right-left)/2);
        ListNode* l2 = doMerge(lists, left+(right-left)/2+1, right);
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(l1 != NULL || l2 != NULL) {
            if(l1 == NULL || (l2 != NULL && l2->val < l1->val)) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};