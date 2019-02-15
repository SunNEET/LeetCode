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

// 簡化查找部分的寫法
/*
    TrieNode:
    (1) 需要一個陣列存指向26(或更多)個字母節點的指標
    (2) 一個 boolean 代表這個有 word 結束在這個位置

    Trie:
    (1) 定義一個 root
    (2) 定義一個 general 的 find，他會在 trie 上移動，當把 word 走完或遇到 NULL 節點就 return
    (3) insert: 這邊跟舊的方法一樣
    (4) search: 拿 find(word) 的回傳結果，判斷是否最後停在非NULL且isWord的節點
    (5) startWith: 拿 find(prefix) 回傳結果，判斷是否停在非NULL節點上就好

*/
class TrieNode {
public:
    TrieNode* next[26];
    bool isWord;
    TrieNode():isWord(false){
        memset(next,NULL,sizeof(next));
    }
};

class Trie {
private:
    TrieNode* root;
    TrieNode* find(string word) {
        TrieNode* run = root;
        // 在 Trie 樹上移動的時候不先判斷有沒有字母節點，就一直給他移動
        // 最後 return 的時候再判斷是不是停在 isWord 上和有沒有跑到NULL節點
        for(int i=0; i<word.length() && run!=NULL; i++) 
            run = run->next[word[i]-'a'];
        return run ;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* run = root;
        for(int i=0;i<word.length();i++) {
            if(!run->next[word[i]-'a'])
                run->next[word[i]-'a'] = new TrieNode();
            run = run->next[word[i]-'a'];
        }
        run->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        // 判斷他最後有沒有停在 isWord
        return p!=NULL && p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        // 只要沒跑到NULL就好
        return p!=NULL;
    }
};