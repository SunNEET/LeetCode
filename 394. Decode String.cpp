class Solution {
    /*
        
        用遞迴解，遞迴過程維護一個變數 idx，代表現在處理到字串的哪裡，
        如果 idx 到了終點或是遇到 ']' 就代表這一層遞迴的工作完成了，返回 res。
        
        每層遞迴開頭如果遇到字母就直接加到 res，如果遇到數字就一直累計 n 直到遇到'['，
        題目保證 input valid，所以必定是 (字母 optional) + 數字 + [] 的順序。
        接著就 move idx 進下一層遞迴，

        Time complexity: O(N)

        Edge cases: 
    */

public:
    string decodeString(string s) {
        int idx = 0;
        return decodeString(s,idx);   
    }
    
    string decodeString(const string& str, int& idx){
        string res = "";
        while(idx < str.length() && str[idx] != ']') {
            if(!isdigit(str[idx])) {
                res += str[idx++];
            } else {
                int n = 0;
                // Getting repeat number. Since the input string is always valid, keep looking right until meet the '['
                while(idx<str.length() && str[idx]!='[')
                    n = n*10 + str[idx++] - '0';
                // cursor is now at '['
                idx++; // move inside
                string sub = decodeString(str,idx);
                // cursor is now at ']'
                idx++; // move outside
                while(n--) 
                    res += sub;
            }    
        }
        return res;
    }
};