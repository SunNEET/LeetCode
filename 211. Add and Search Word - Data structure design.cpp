/*
    基本上就是用 Trie 做，唯一的差別就是多了個 "."，需要在search的時候特別處理這個符號。
    方法很單純，就是遇到當前 word 字元是 "." 的，就枚舉當前 Trie 節點的所有下一個可能(next[0~25])，
    然後遞迴處理。

    Tips: 枚舉下去前要讓當前 run 跟著動，否則即使next[]全都不ok，有可能run停在OK的位置而判斷出錯
    e.g. dic["a"], search("a.")，這個實際上長度超過了，但必須讓 run 動往下一個 next，判斷才會正確
    
*/
class TrieNode {
public:
    TrieNode* next[26];
    bool is_word;
    TrieNode(): is_word(false) {
        memset(next, NULL, sizeof(next));
    }
};

class WordDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++) {
            if(!p->next[word[i]-'a'])
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word, root);
    }
private: 
    bool query(string word, TrieNode* node) {
        TrieNode* run = node;
        for(int i=0;i<(int)word.length() && run!=NULL;i++) {
            if(word[i]!='.')
                run = run->next[word[i]-'a'];
            else {
                TrieNode* tmp = run;
                for(int j=0; j<26; j++) {
                    run = tmp->next[j];
                    if(query(word.substr(i+1),run))
                        return true;
                }
            }
        }
        return run!=NULL && run->is_word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */