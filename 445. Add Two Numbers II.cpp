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
        從前排到後，為了要讓他們同時從最後面出發，需要用 stack 或 recursive 來做。
        這邊用 stack 比較好做，先把 value 全 push 進兩個 stack 裡，再同時從兩邊 pop 出來就可以了。

        Time complexity: O(N)
        Space complexity: O(N)
    */
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1 != NULL) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int sum = 0;
        ListNode *p = new ListNode(0);
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            p->val = sum%10;
            ListNode* head = new ListNode(sum/10);
            head->next = p;
            p = head;
            sum /= 10;
        }
        
        return p->val == 0 ? p->next : p ;
    }
};

/* Java Recursive 版本
事先算好兩個 list 的長度，然後算出他們的 difference，然後遞迴下去的時候要確保 l1 > l2
因為在 diff 還沒歸零的情況下只會讓 l1->next 往下遞迴，l2 依舊傳 l2
當 diff 已經是 0 的時候，就可以兩個一起 l1->next, l2->next 遞迴到 null 了

忽略前面多出來的 l2 nodes 的技巧是判斷當下 diff 是否為 0，如果不是，代表已經退回到超過他原本的長度了
*/
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int size1 = getLength(l1);
        int size2 = getLength(l2);
        ListNode head = new ListNode(1);
        // Make sure l1.length >= l2.length
        head.next = size1 < size2 ? helper(l2, l1, size2 - size1) : helper(l1, l2, size1 - size2);
        // Handle the first digit
        if (head.next.val > 9) {
            head.next.val = head.next.val % 10;
            return head;
        }
        return head.next;
    }
    // get length of the list
    public int getLength(ListNode l) {
        int count = 0;
        while(l != null) {
            l = l.next;
            count++;
        }
        return count;
    }
    // offset is the difference of length between l1 and l2
    public ListNode helper(ListNode l1, ListNode l2, int offset) {
        if (l1 == null) return null;
        // check whether l1 becomes the same length as l2
        ListNode result = offset == 0 ? new ListNode(l1.val + l2.val) : new ListNode(l1.val);
        ListNode post = offset == 0 ? helper(l1.next, l2.next, 0) : helper(l1.next, l2, offset - 1);
        // handle carry 
        if (post != null && post.val > 9) {
            result.val += 1;
            post.val = post.val % 10;
        }
        // combine nodes
        result.next = post;
        return result;
    }