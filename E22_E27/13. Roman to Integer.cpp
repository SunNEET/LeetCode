class Solution {
    // 其實不需要先拆開，從最右邊開始往左一個一個看羅馬數字就好了。
    // 如果s[i]代表的value < s[i+1] ( 例如: IV(4), IX(9), XM(990) )的話
    // 就把目前的sum減去s[i]的value (承上例： 5-1, 10-1, 1000-10)
    // 反之，就把目前的s[i]累加上去(例如: VIII(8), XVI(16), CMXCIV(994))
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int len = s.length();
        if(!len) return 0;
        int sum = roman[s[len-1]];
        for(int i=len-2;i>=0;i--){
            if(roman[s[i]] < roman[s[i+1]])
                sum -= roman[s[i]];
            else
                sum += roman[s[i]];
        }
        return sum;
    }
};