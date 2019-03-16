/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    /*
        難點在於處理新的 list 上的 random pointer，因為一開始那些節點不存在，不能直接在第一次看到就把他接好
        這邊可以用一個 hashmap 建立 l1 和 l2 節點的對應關係
        第一次先走一遍 l1 把 l2 的 node 都 new 出來並接好，同時用 map 紀錄新舊節點的對應
        
        這樣在第二次 loop 的時候，就可以一邊看 l1 的 random 是指向哪個節點，
        讓 l2 的 random 也指向他的 list 上對應的那個節點
        
        Time: O(N)
        Space: O(N)
    */
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* newhead = new Node(head->val,NULL,NULL);
        Node* l2_cur = newhead;
        Node* l1_cur = head->next;
        unordered_map<Node*,Node*> m_rdm; // map l1 node to l2 node with same position
        m_rdm[head] = l2_cur;
        
        while(l1_cur) {
            Node* l2_nxt = new Node(l1_cur->val,NULL,NULL);
            l2_cur->next = l2_nxt;
            m_rdm[l1_cur] = l2_nxt;
            l2_cur = l2_cur->next;
            l1_cur = l1_cur->next;
        }
        
        l2_cur = newhead;
        l1_cur = head;
        
        while(l2_cur) {
            l2_cur->random = m_rdm[l1_cur->random];
            l2_cur = l2_cur->next;
            l1_cur = l1_cur->next;
        }
        return newhead;
    }
};

class Solution {
    /*
        不用 extra space 的做法，在每個節點後面複製一個一樣的節點，再把他們的 random 接起來
        用 cur->next->random = cur->random->next
        道理很簡單，因為 cur->random 指向的是原本的點，那他的下一個就是有同一個的複製出來的新的點
        
        l1: 1->2->3->NULL
        
        1->random = 2, 2->random
        l1': 1 -> 1'-> 2 -> 2'->3->3'->NULL
             ^r3       ^rp1 ^rp1'
                       ^rp2
        rp1' = rp1->next
        
        之後再用間隔一個的方式 extract 出新的節點。(同時 restore 被亂接的 l1)
        
        坑點：
        最後 extract 的時候要注意先暫存 cur->next->next，
        不然 ncur 的改變會造成 cur->next->next 實際是指向 l2 的節點
    */
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* cur = head;
        while(cur) {
            Node* cp = new Node(cur->val, NULL, NULL);
            cp->next = cur->next;
            cur->next = cp;
            cur = cp->next;
        }   
        cur = head;
        while(cur) {
            if(cur->random != NULL) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head;
        Node* newhead = cur->next;
        Node* ncur = newhead;
        while(ncur->next) {
            Node* nxt = cur->next->next;
            ncur->next = ncur->next->next;
            ncur = ncur->next;
            cur->next = nxt;
            cur = cur->next;
        }
        cur->next = NULL;
        return newhead;
    }
};