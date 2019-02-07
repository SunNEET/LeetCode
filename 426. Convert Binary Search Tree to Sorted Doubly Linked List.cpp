/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    /*
    要把 BST 轉成 sorted 相關的就是用 inorder traversal 了
    為了要將節點互串還需要一個額外的 Node* pre，用來記錄前一個訪問完的節點。
    另外還需要一個 dummy node 作為 pre，讓他的 right 指向第一個訪問到的點
    這樣最後 inorder 完才能讓最後一個 node 跟 第一個 node 串起來，並且回傳新起點。
    */
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node* dummy = new Node(0,NULL,NULL);
        Node* pre = dummy;
        inorder(root,pre);
        pre->right = dummy->right;
        dummy->right->left = pre;
        return dummy->right;
    }
    void inorder(Node* cur, Node*& pre) {
        if(!cur) return;
        // L
        inorder(cur->left, pre);
        // V
        pre->right = cur;
        cur->left = pre;
        pre = cur;
        // R
        inorder(cur->right,pre);
    }
};