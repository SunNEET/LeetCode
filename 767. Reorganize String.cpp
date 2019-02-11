class Solution {
    /*
        用 greedy 的直覺作法，先從出現頻率最高字母開始加到新字串
        如果接下來最高頻率的還是跟目前字串尾巴的字母一樣，就必須拿次高頻率的字母
        
        如果要拿次高頻率的字母時，priority_queue裡已經空了，代表沒字母能用了，回傳""
        否則就把這個次高頻率的字母加到字串尾巴，再把最高頻率的加回去
        
        以上的動作在做完後都需要把字母的map裡的value-1後塞回priority_queue
        Time: 
        Space: O(L)
    */
    class ComparePair {
    public:
        bool operator()(const pair<char,int>& a, const pair<char,int>& b) {
            return a.second < b.second;
        }
    };
public:
    string reorganizeString(string S) {
        unordered_map<char,int> occurrence;
        priority_queue<pair<char,int>, vector<pair<char,int>>, ComparePair> pq;
        for(int i=0; i<S.length(); i++) 
            occurrence[S[i]]++;
        for(auto iter = occurrence.begin(); iter!=occurrence.end(); iter++)
            pq.push(*iter);
        string ans = "";
        while(!pq.empty()) {
            pair<char,int> ch = pq.top();
            pq.pop();
            if(ans.length() == 0 || ans.back()!=ch.first) {
                ans += ch.first;
                ch.second--;
                if(ch.second) pq.push(ch);
            } else {
                if(pq.empty()) return "";
                pair<char,int> ch2 = pq.top();
                pq.pop();
                ans += ch2.first;
                ch2.second--;
                if(ch2.second) pq.push(ch2);
                pq.push(ch);
            }
        }
        return ans;
    }
};