/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    /*
        用 for 迴圈來 do recursion for each child
    */
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int height = 1;
        for(auto child_node : root->children) {
            height = max(height, maxDepth(child_node)+1);
        }
        return height;
    }
};