class Solution {
/*
    記得有想法差不多題目，忘了題號。
    基本上就是 two pointer 維護一個 sliding window 然後用 unordered_map 維護獨立的字元數
    當 map 的 size 超過 k 就表示種類太多，該縮左界了，縮到有個數的次數已經是0了就把它從map中移除
*/
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int slen = s.length();
        if(!slen || !k) return 0;
        unordered_map<char,int> distchar;
        int left = 0, right = 0, maxlen = 1;
        while(right < slen) {
            distchar[s[right]]++;
            while(left < right && distchar.size() > k) {
                distchar[s[left]]--;
                if(!distchar[s[left]])
                    distchar.erase(s[left]);
                left++;
            }
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};