/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    /*
        只是要實作的話，可以用 preorder traversing 把節點按 visiting 順序 push 進 字串，字串間用 # 來分隔。

        Space complexity: O(2n + 1)
        clarify: 
        (1) How many tree nodes the input may have?
        (2) Assume there are N nodes. Does the tree nodes number always start from 0 to N-1 ?
        (3) How big a single node number can be?
    */
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        serial(root, res);
        cout << res << endl;
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#") return NULL;
        stringstream ss(data);
        return deserial(ss);
    }
    
private:
    void serial(TreeNode* cur, string& res) {
        if(!cur) {
            res += "# ";
            return;
        }
        // pre-order
        res += to_string(cur->val) + ' ';
        serial(cur->left, res);
        serial(cur->right, res);
    }
    
    TreeNode* deserial(stringstream& ss) {
        string str;
        getline(ss, str, ' ');
        if(str == "#")
            return NULL;
        else {
            TreeNode* cur = new TreeNode(stoi(str));
            cur->left = deserial(ss);
            cur->right = deserial(ss);
            return cur;
        }
    }
    
    // TreeNode* deserialize(TreeNode* cur, string)
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


// 比較精簡的 serialize 寫法
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == NULL) return "#";
    string res = "";
    res += to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    cout << res << endl;
    return res;
}