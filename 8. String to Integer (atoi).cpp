class Solution {
    /*
        (1) leading zeroes
        (2) sign of the number
        (3) overflow
        (4) invalid input
    */
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, i = 0;
        while(str[i] == ' ') { i++; } // (1)
        
        if (str[i] == '-' || str[i] == '+') // (2)
            sign = str[i++] == '-' ? -1 : 1;
        
        while (str[i] >= '0' && str[i] <= '9') { // (4) invalid input
            if (base > INT_MAX/10) { // (3) overflow
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base *= 10; 
            if(base > INT_MAX-(str[i]-'0')) { // (3) overflow
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base += (str[i++]-'0');
        }
        return sign*base;
    }
};