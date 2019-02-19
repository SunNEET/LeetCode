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
    Use two pointers: the slow pointer takes one step at a time, the fast pointer takes two steps at a time. 
    Keep doing this until the next step or the next two steps of the fast pointer is NULL.
    Break the loop, now the slow pointer is just at the left median position
    Reverse the remained linked list from the next position of the slow pointer, compare it to the head

    使用快慢指針的技巧：slow 一次走一步, fast 一次走兩步, 當 fast 再往後走(1步或2步)就遇到 null 的話
    就跳出迴圈, 此時的 slow 就會正好處於 linked list 的左中位置(偶數左中,奇數就中間)
    從slow的下一個位置開始把 linked list 反轉，然後再跟head比一次
  */
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow!=NULL) {
            if(slow->val != head->val) 
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode *pre = NULL, *cur = head;
        while(cur!=NULL) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

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
    另一個非常聰明且不會破壞 Linked list 結構的方法 - 用遞回
    同時傳入兩個指向 head 的 pointer，其中一個要是 reference, 假設就叫head，另一個叫cur
    當 cur 往下遞回到底的時候，開始跟 head->val 做比較，return 的時候同時把 head 移到 head->next
    這樣就像two pointer從頭尾兩側出發一樣
  */
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        return traverse(head, head);
    }
    bool traverse(ListNode* cur, ListNode*& head) {
        if(!cur) return true;
        bool check = traverse(cur->next, head) && (cur->val == head->val);
        head = head->next;
        return check;
    }
};