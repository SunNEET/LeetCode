class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        int cnt = 0;
        for(auto ch : J) jewels.insert(ch);
        for(auto ch : S) {
            if(jewels.count(ch)) 
                cnt++;
        }
        return cnt;
    }
};