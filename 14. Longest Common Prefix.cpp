class Solution {
    /*
        從 0 開始枚舉 idx，然後比對所有字串的 idx 字元，有不合就 return
        Time: O(N*M), where N is size of strs, M is minimum length of these strings
        Space: O(1)
    */
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        string res = "";
        if(!strs.size()) return res;
        while(idx < strs[0].length()) {
            char curc = strs[0][idx];
            for(int i=1; i<strs.size(); i++) {
                if(idx >= strs[i].length() || strs[i][idx] != curc)
                    return res;
            }
            res += curc;
            idx++;
        }
        return res;
    }
};