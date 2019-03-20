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
        快慢指針
        Time:  O(N)
        Space: O(N)
    */
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast) {
            if(!fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
};

class Solution {
    /*
        用一個set存訪問過的點
        Time:  O(N)
        Space: O(N)
    */
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode *cur = head;
        while(cur) {
            visited.insert(cur);
            if(cur->next && visited.count(cur->next)) return true;
            cur = cur->next;
        }
        return false;
    }
};