class Solution {
    /*
        仔細處理 overflow 邊界
        因為INT_MIN 大 INT_MAX 1, 必須特判
        ans*10 之前先判斷 ans > INT_MAX/10
        ans + x%10 之前先判斷 ans > INT_MAX - x%10;
    */
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int ans = 0;
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        while(x) {
            if(ans > INT_MAX/10) return 0;
            int tens = ans*10;
            int digit = x%10;
            if(ans > INT_MAX - digit) return 0;
            ans = tens + digit;
            x /= 10;
        }
        return sign*ans;
    }
};