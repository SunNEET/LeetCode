class Solution {
/*
    We can address this by sliding window & hashmap
    Hashmap is used to record the occurrence of each character.
    We can use it to know if a new character alreary existed in current sliding window

    If there is no duplicate, then we move the right bound of the sliding window one step toward right
    Otherwise, we have to keep moving the left bound of the sliding window toward right
    until there is no duplicate.
*/
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_map<char,int> cnt;
        while(j<s.length()) {
            cnt[s[j]]++;
            while(cnt[s[j]]>1) {
                cnt[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
            
        }
        return ans;
    }
};