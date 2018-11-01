class Solution {
    struct TrieNode {
        vector<TrieNode*> children;
        vector<int> index;
        TrieNode(): children(26, nullptr) {} // NULL is deprecated. if you pass a nullptr to any place that does type deduction, such as a template function, C++ will treat nullptr as a pointer whereas it will treat NULL as an integer.
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i=0;i<words.size();i++) {
            TrieNode* cur = root;
            for(int j=0;j<words[i].size();j++) {
                if(!cur->children[words[i][j]-'a']) {
                    cur->children[words[i][j]-'a'] = new TrieNode();
                }
                cur = cur->children[words[i][j]-'a'];
                cur->index.push_back(i);
            }
        }
        return root;
    }
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if(words.size()==0) return {};
        TrieNode* root = buildTrie(words);
        vector<vector<string>> ans;
        vector<string> tmp(words[0].size());
        for(int i=0;i<words.size();i++) {
            tmp[0] = words[i];
            DFS(root,1,tmp,ans,words);
        }
        return ans;
    }
    
    void DFS(TrieNode* root, int depth, vector<string>&tmp, vector<vector<string>>& ans, vector<string>& words) {
        if(depth >= words[0].size()) {
            ans.push_back(tmp);
            return;
        }
        string str="";
        for(int i=0;i<depth;i++)
            str += tmp[i][depth];
        TrieNode* cur = root;
        for(int i=0;i<str.length();i++) {
            if(!cur->children[str[i]-'a']) return;
            cur = cur->children[str[i]-'a'];
        }
        for(int i=0;i<cur->index.size();i++) {
            tmp[depth]=words[cur->index[i]];
            DFS(root,depth+1,tmp,ans,words);
        }
    }
};