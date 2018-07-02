class Solution {
// 本體是枚舉, 但要靠dp優化
// 令dp[i] = s[0~i-1] 是可以拆解的, 也就是能用wordDict裡的word拼出來.
// 枚舉的方式是從s[0]開始遍歷, 對每個i往左看(用j往左掃), 
// 直到有dp[j]=true的情況, 代表可以從這裡接下去, 
// 這是一個可行的斷點, 因為前面有一串word能結束j-1在或是j是起點0
// 所以將s[j~i]切成子字串, 丟到wordDict判斷有沒有這個word存在

// 有的話, 就是將dp[i+1] = true; 

// 沒有的話, 就是j繼續往左掃, 掃到其他有dp[j]=true的組合然後一樣看有沒有s[j~i]這個word
// 還是沒有的話, 那就i繼續往右, 然後重複上面的步驟
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        dp[0] = true; // 起點必定可以往後接, 所以設為true
        for(int i=0; i<s.length(); i++) {
            // j往左看, 找到可以接的點並切出子字串, 丟到vector裡判斷存不存在
            for(int j=i;j>=0;j--) {
                if(dp[j] && find(wordDict.begin(), 
                                 wordDict.end(), 
                                 s.substr(j,i-j+1))!=wordDict.end() )
                    dp[i+1] =true;
            }
        }
        return dp[s.length()];
    }
};