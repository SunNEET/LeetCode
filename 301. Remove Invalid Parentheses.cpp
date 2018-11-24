class Solution {
    /*
        基本流程：
        首先，計算有多少多餘的 left and right bracket。
        接著，用 DFS 遞迴，從 start 開始找要移除的 right 和 left bracket，當 r 和 l 都有的時候，先移除 r 的，再移除 l 的，這樣可以減少很多最後是 invalid 的情況，
        每移除一個就 r-1 或 l-1 然後往下遞回。
        最後，當 r==0 且 l==0 時，判斷目前這樣的字串bracket 是否合法 (另外再寫個function 判斷)

        Clarify: 
        (1)

        Time Complexity: O(n*2^n)
        Space Complexity: O(2^n)
    */
    
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        vector<string> res;
        // count redundant bracket
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(') l++;
            else if (s[i]==')'){
                if(l==0) r++;
                else l--;
            }
        }
        DFS(s, res, 0, l, r);
        return res;
    }
    
private:
    bool isValid(string s) {
        int cnt = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(') cnt++;
            if(s[i]==')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
    
    void DFS(const string& s, vector<string>& res, int start, int l, int r) {
        if(l==0 && r==0 && isValid(s))
            res.push_back(s);
        for(int i=start; i<s.length(); i++) {
            string cur = s;
            if(i>start && s[i]==s[i-1]) continue;
            if(r > 0 && s[i]==')') {
                cur.erase(i,1);
                DFS(cur,res,i,l,r-1);
            } else if(r == 0 && l > 0 && s[i]=='(') {
                cur.erase(i,1);
                DFS(cur,res,i,l-1,r);
            }
        }
    }
    
    
};