/*
    基本的 Trie 實作，分成定義 TrieNode 和 Trie
    TrieNode:
    (1) 需要一個陣列存指向26(或更多)個字母節點的指標
    (2) 一個 boolean 代表這個有 word 結束在這個位置

    Trie:
    (1) 定義一個 root
    (2) 定義 insert，每次都從 root 往下找，遇到字母節點是 null 的就 new 一個
    (3) 定義 search，每次都從 root 往下找，如果遇到 null 節點就直接 return false，結束的節點不是 word 也 return false
    (4) 定義 startWith，條件寬鬆的(3)，只判斷有沒有 null 節點
*/

class TrieNode {
public:
    TrieNode* next[26];
    bool is_word;
    
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++) {
            if(p->next[word[i]-'a'] == NULL)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++) {
            if(p->next[word[i]-'a']==NULL)
                return false;
            p = p->next[word[i]-'a'];
        }
        return p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i=0;i<prefix.length();i++) {
            if(p->next[prefix[i]-'a']==NULL)
                return false;
            p = p->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */