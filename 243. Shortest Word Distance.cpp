class Solution {
    /*
        Hashmap 紀錄 word 最近出現的index
        如果idx_of裡有目標的兩個word就比較index間的距離
        因為會一直更新idx_of，所以如果有更短的就會更新dist
    */
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string,int> idx_of; // keep the most recent one
        int dist = INT_MAX;
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            idx_of[word] = i;
            if(idx_of.count(word1) && idx_of.count(word2)) {
                dist = min(dist,abs(idx_of[word1] - idx_of[word2]));
            }
        }
        return dist;
    }
};