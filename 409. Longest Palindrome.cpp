class Solution {
    /*
        unordered_set<char> + count
        已經有count的情況下表示現在這個字元能跟他湊成偶數, 所以可以形成回文的一部分
        而回文裡可以接受一個字元在最中間只出現一次，所以如果 for loop 結束裡面還有東西
        就 return 2*count + 1
        否則就是 2*count 而已
    */
public:
    int longestPalindrome(string s) {
        if(!s.length()) return 0;
        unordered_set<char> hs;
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(hs.count(s[i])) {
                hs.erase(s[i]);
                count++;
            } else {
                hs.insert(s[i]);
            }
        }
        if(!hs.empty()) return count*2+1;
        return count*2;
    }
};