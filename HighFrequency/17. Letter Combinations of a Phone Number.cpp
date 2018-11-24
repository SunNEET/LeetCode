class Solution {
private:
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
        string cur="";
        DFS(digits, ans, 0, cur);
        return ans;
    }
    void DFS(const string& digits, vector<string>& ans, int depth, string cur) {
        if(depth == digits.length()) {
            ans.push_back(cur);
            return;
        }
        char c = digits[depth];
        for(int i=0;i<hash[c].length();i++) {
            // cur.push_back(hash[c][i]);
            DFS(digits, ans, depth+1, cur+hash[c][i]);
            // cur.pop_back();
        }
        return;
    }
};