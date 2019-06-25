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
        北爛題，沒有給head，只給node然後要從list上刪掉這個點。
        因為題目條件說不會有要砍尾巴的情況，所以其實就是複製next的val到這個點上，然後現在的next指向原本next的next
        Time:   O(1)
        Space:  O(1)
    */
public:
    void deleteNode(ListNode* node) {
        node->val =  node->next->val;
        node->next = node->next->next;
    }
};