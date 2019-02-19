class Solution {
/*
    We can address this by sliding window & hashmap
    Hashmap is used to record the occurrence of each character.
    We can use it to know if a new character alreary existed in current sliding window

    If there is no duplicate, then we move the right bound of the sliding window one step toward right
    Otherwise, we have to keep moving the left bound of the sliding window toward right
    until there is no duplicate.

    Time: O(N)
    Space: O(N)
*/
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans = 0;
        unordered_map<char,int> cnt;
        while(right < s.length()) {
            cnt[s[right]]++;
            while(cnt[s[right]]>1) {
                cnt[s[right]]--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};