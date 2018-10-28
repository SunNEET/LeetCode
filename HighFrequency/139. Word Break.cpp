class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1,false); // dp[i] denotes s[0~i-1] can be split up, so we're able to attach it from i
        dp[0] = true;
        for(int i=0;i<s.length();i++) {
            // Make j go to left while checking...
            // (1) if there is any dp[j] equals true, which means we can attach a new words right after it.
            // (2) substring s[j~i] is a word in the dictionary.
            for(int j=i;j>=0;j--) {
                if(dp[j] && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j+1))!=wordDict.end()) {
                    // edge case: remember dp[i] means s[0~i-1] can be split up. When we found s[j~i] can be 
                    // split up, we should set dp[i+1] to true, which means other new words can attach from index i+1
                    dp[i+1] = true;
                }
            }
        }
        return dp[s.length()];
    }
};