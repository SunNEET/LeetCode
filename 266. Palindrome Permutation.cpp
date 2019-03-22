class Solution {
    /*
        Hashmap紀錄char出現次數,最多只能有一個字母出現odd次
    */
public:
    bool canPermutePalindrome(string s) {
        if(!s.length()) return false;
        unordered_map<char,int> count;
        for(char ch : s) count[ch]++;
        bool has_odd_freq = false;
        for(auto entry : count) {
            int cnt = entry.second;
            if(cnt&1 && !has_odd_freq) has_odd_freq = true;
            else if(cnt&1 && has_odd_freq) return false;
        }
        return true;
    }
};