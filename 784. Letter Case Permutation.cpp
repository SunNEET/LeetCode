class Solution {
    /*
        Solution: DFS枚舉，遇到字母就枚舉大小寫兩種可能，不是的話就直接往下一層
        Time complexity: O(2^N) 
        Edge cases: "" return ""
    */
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string tmp = "";
        DFS(res,S,tmp,0);
        return res;
    }
    void DFS(vector<string>& res, const string& S, string tmp, int depth) {
        if(depth == S.length()){
            res.push_back(tmp);
            return;
        }
        if(isalpha(S[depth])){
            DFS(res,S,tmp+(char)tolower(S[depth]),depth+1);
            DFS(res,S,tmp+(char)toupper(S[depth]),depth+1);
        } else {
            DFS(res,S,tmp+S[depth],depth+1);
        }
    }
};