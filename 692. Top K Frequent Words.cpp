class Solution {
    /*
        先用 hashmap 算 word frequency，然後把<word,freq> 的 pair push進pq
        寫 compare class 讓他用 freq 排序，做 minHeap，所以比較要反過來(return >)
                
    */
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for(string word : words)
            cnt[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for(auto word_freq : cnt) {
            pq.push({word_freq.first, word_freq.second});
            if(pq.size() > k)
                pq.pop();
        }
        vector<string> res;
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    struct Compare {
        // minHeap, increasing, 當作把符合條件的 l 往pq的深處放就對了
        bool operator() (pair<string, int>& l, pair<string, int>& r) {
            return l.second > r.second || (l.second == r.second && l.first.compare(r.first) < 0);
        }
    };
};
