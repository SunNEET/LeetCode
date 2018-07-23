/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // 用兩個stack來塞兩個list的元素, 這樣兩邊的top就會是最右邊的位數
    // 取出元素相加, 再塞到一個stack裡, 此時top到bottom正好是左邊的位數到右邊的位數
    // 所以在用他們弄個List出來 就好了
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        stack<int> tmp;
        while(l1!=NULL) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!st1.empty() && !st2.empty()) {
            int val1 = st1.top();
            st1.pop();
            int val2 = st2.top();
            st2.pop();
            int sum = val1 + val2 + carry;
            carry = sum/10;
            tmp.push(sum%10);
        }
        // 把還沒空的清空, 這時不論原本是st1還是st2, 一律把沒空的當作st1
        if(!st2.empty()) st1 = st2;
        // 這樣就只要做一個while就好
        while(!st1.empty()) {
            int val = st1.top();
            st1.pop();
            int sum = val + carry;
            carry = sum/10;
            tmp.push(sum%10);
        }
        // 判斷最後一個進位
        if(carry)
            tmp.push(1);
        ListNode* dump = new ListNode(0);
        ListNode* ret = dump;
        while(!tmp.empty()) {
            int val = tmp.top();
            dump->next = new ListNode(val);
            tmp.pop();
            dump = dump->next;
        }
        return ret->next;
    }
};