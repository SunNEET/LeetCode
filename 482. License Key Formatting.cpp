class Solution {
    /* 
        用isalnum判斷是不是字母跟數字，每K個就加入"-"，返回前要記得判斷有沒有 leading "-"。
    */
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int cnt = 0;
        for(int i=S.length()-1; i>=0; i--) {
            if(isalnum(S[i])) {
                res += toupper(S[i]);
                if(++cnt == K && i) {
                    res += "-";
                    cnt = 0;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res[0] != '-' ? res : res.substr(1, res.length() - 1);
    }
};