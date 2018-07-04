class Solution {
    // 直接枚舉 每種情況, 對每個字元都考慮枚舉'(', ')'
    // 只是要考慮幾個條件
    // 1. 目前'('的數量要大於')', 才能放')'
    // 2. '('的數量不能超過n
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp = "";
        DFS(0, n, tmp, ans, 0, 0);
        return ans;
    }
    void DFS(int d, int& n, string tmp, vector<string>& ans, int left, int right){
        if(d == 2*n){
            ans.push_back(tmp);
            return;
        }
        // 左括號
        if(left < n)
            DFS(d+1, n, tmp+"(", ans, left+1, right);
        // 右括號
        if(left > right && right < n)
            DFS(d+1, n, tmp+")", ans, left, right+1);
            
        return;
    }
};