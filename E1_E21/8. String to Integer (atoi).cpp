class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, i = 0;
        //跳過開頭所有的空白
        while (str[i] == ' ') { i++; }
        // 判斷正負號, 這邊用int存, 最後的結果會是數字的1/-1, 可以直接拿來乘
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2*(str[i++] == '-'); 
        }
        // 排除不有效的輸入, 也就是非數字
        while (str[i] >= '0' && str[i] <= '9') {
            // 處理overflow
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) 
                    return INT_MAX;
                else 
                    return INT_MIN;
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};