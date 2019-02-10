class Solution {
    /*
    用對單字的每個位置枚舉a~z的方式來做BFS, 一路做到能找到終點為止

    複雜度修正：
    time: O(n * 26 * l), n 是 # of word in wordlist, l is length of word
    space: O(n)

    Explain: 每一個單詞得到它所有距離為1的單詞（neighbor）的時間複雜度是O(26*l); 
    如果 wordlist 中有n個詞，那麼得到所有單詞的 neighbor 的時間複雜度是O(n*26*l)
    而如果存在從 begin 到 end 的通路，它一定這n*26*l個結果中。
    這一過程也對應你代碼中的兩個for循環。所以時間複雜度應該是O(n*26*l) -> O(n*l).
    */ 
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // 不在字典裡, 變不出來
        if(!dict.count(endWord)) return 0;
        
        int len = beginWord.length();
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int step = 0;
        while(!q1.empty() && !q2.empty()) {
            step++;
            // 總是先擴展比較小的queue
            if(q1.size() > q2.size()) 
                std::swap(q1,q2);
            // 每一位都把26個字元試試
            unordered_set<string> q;
            for(string word : q1) {
                for(int i=0;i<len;i++) {
                    char c = word[i]; 
                    for(int j='a';j<='z';j++) {
                        word[i] = j;
                        // Match到了
                        if(q2.count(word)) return step+1;
                        if(!dict.count(word)) continue;
                        // 用過的字就不能用了
                        dict.erase(word);
                        q.insert(word);
                    }
                    word[i] = c;
                }
            }
            std::swap(q1,q);
        }
        return 0;
    }
};