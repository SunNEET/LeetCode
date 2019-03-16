class Solution {
    /*
        用set紀錄可以換的單字，然後用BFS嘗試可能的單字
        Time:  O(N*L), N is the number of words in wordList, L is the length of the word
        Space: O(N)
    */
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(!wordList.size()) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()) {
            auto word = q.front(); q.pop();
            if(word.first == endWord) return word.second;
            for(int i=0; i<word.first.length(); i++) {
                char tmp = word.first[i];
                for(int j=0; j<26; j++) {
                    word.first[i] = j+'a';
                    if(dict.count(word.first)) {
                        q.push(make_pair(word.first, word.second+1));
                        dict.erase(word.first);
                    }
                }
                word.first[i] = tmp;
            }
        }
        return 0;
    }
};