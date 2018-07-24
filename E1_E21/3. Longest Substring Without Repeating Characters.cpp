class Solution {
    // 無腦作法,之後會改進成DP
public:
    int lengthOfLongestSubstring(string s) {
        bool hash[128];
        int len = s.length();
        int ans = 0;
        for(int i=0;i<len-1;i++){
            hash[s[i]]=true;
            for(int j=i+1;j<len;j++){
                if(!hash[s[j]]){
                    ans = max(ans,j-i);
                    hash[s[j]]=true;
                }
                else
                    break;
            }
            memset(hash,0,sizeof(hash));
        }
        ans = s.length()>0 ? ans+1 : 0;
        return ans;
    }
};