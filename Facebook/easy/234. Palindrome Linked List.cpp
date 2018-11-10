/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 快慢指針的技巧：slow 一次走一步, fast 一次走兩步, 當 fast 再往後走(1步或2步)就遇到 null 的話
    // 就跳出迴圈, 此時的 slow 就會正好處於 linked list 的左中位置(偶數左中,奇數就中間)
    // 從slow的下一個位置開始把 linked list 反轉，然後再跟head比一次
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) { // error
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
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur!=NULL) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};

class Solution {
    // 另一個非常聰明且不會破壞 Linked list 結構的方法 - 用遞回
    // 維護一個 tmp，並且這個 tmp 指向 head，並且只有在 linked list 遞迴到底開始 return 的時候 
    // 再同時跟要 return 的 node 比較，然後移往下一個，就像two pointer從頭尾兩側出發一樣
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* tmp = head;
        return traverse(head, tmp);
    }
    bool traverse(ListNode* cur, ListNode*& head) {
        if(!cur) return true;
        bool check = traverse(cur->next, head) && (cur->val == head->val);
        head = head->next;
        return check;
    }
    
};