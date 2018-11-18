class Solution {
    // 把問題簡單化，用 "/" 切割字串，遇到"."或空白就跳過，只考慮 目錄名稱 和 ".."。
    // 用一個類似 stack 的結構來維護這串路徑，當遇到目錄名就把它推進 stack 裡，
    // 當遇到 .. 時就pop掉，這樣最後留下的就是當前的路徑了
    // 最後再把 "/" 加回目錄名稱前就可以了
    
    // Corner cases: 
    // (1) "/../" => "/"
    // (2) multiple slashes "/a/////b" => "/a/b"
    // (3) "" => "/"
public:
    string simplifyPath(string path) {
        string res,tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp=="" || tmp==".") continue;
            if(tmp==".." && !stk.empty()) stk.pop_back();
            else if(tmp!="..") stk.push_back(tmp);
        }
        for(auto dir : stk)
            res += "/" + dir;
        return res.empty() ? "/" : res;
    }
};