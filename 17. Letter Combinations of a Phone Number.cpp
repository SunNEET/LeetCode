class Solution {
    // 用DFS按順序枚舉每種組合
    unordered_map<char,string> hash = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.length()) return {};
        vector<string> ans;
        string tmp="";
        DFS(digits,ans,0,tmp);
        return ans;
    }
    
    void DFS(string& digits, vector<string>& ans, int idx, string& tmp) {
        char num = digits[idx];
        if(idx == digits.length()) {
            ans.push_back(tmp);
            return ;
        }
        for(int i=0;i<hash[num].length();i++) {
            tmp.push_back(hash[num][i]);
            DFS(digits,ans,idx+1,tmp);
            tmp.pop_back();
        }
        return ;
    }
};