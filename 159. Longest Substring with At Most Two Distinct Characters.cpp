class Solution {
    /*
        sliding window 解決
        Time: O(N)
        Space: O(N)
    */
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> window;
        int lf = 0, rt = 0, maxlen = 0;
        while(rt < s.length()) {
            window[s[rt]]++;
            while(window.size() > 2) {
                window[s[lf]]--;
                if(!window[s[lf]])
                    window.erase(s[lf]);
                lf++;
            }
            maxlen = max(maxlen, rt - lf + 1);
            rt++;
        }
        return maxlen;
    }
};