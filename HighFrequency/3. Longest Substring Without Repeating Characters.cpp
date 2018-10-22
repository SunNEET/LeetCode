class Solution {
// 靠 sliding window + hash 來做
// 在新元素沒重複的時候就往右邊長
// 如果遇到重複的就要一直縮左界, 直到沒有跟新元素重複為止
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