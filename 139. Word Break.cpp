class Solution {
    /*
        DP[i] denotes if s[0~i-1] can be splitted up into the words of the dictionary
        So if DP[i] is true, that means we can try to find a substring starting from i that is a word in the dict
        
        Time:  O(N^2)
        Space: O(N)
    */    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> DP(s.length()+1);
        DP[0] = true;
        for(int i=0; i<s.length(); i++) {
            for(int j=i; j>=0; j--) {
                if(DP[j] && dict.count(s.substr(j, i-j+1))) {
                    DP[i+1] = true;
                }
            }
        }
        return DP[s.length()];
    }
};