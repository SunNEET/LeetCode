class Solution {
    /*
        不用long，巧秒的處理 -2^31 和其他會造成 overflow 的計算
    */
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend<0)^(divisor<0) ? -1 : 1, quotient = 0;
        if(dividend == INT_MIN) {
            if(divisor == -1) return INT_MAX;
            if(divisor == 1) return INT_MIN;
            if(divisor == INT_MIN) return 1;
            /* 
                為了避免等等 abs(dividend) overflow
                所以先減去一份 divisor，只是因為現在是負數
                其實就跟轉成絕對值後減掉 divisor 是一樣的
            */
            dividend += abs(divisor);
            quotient++;
        }
        if(divisor == INT_MIN) return 0; // no value can be subtracted by abs(INT_MIN) and still >= 0
        dividend = abs(dividend);
        divisor = abs(divisor); 
        while(dividend >= divisor) {
            int tmp = divisor, mul = 1;
            // 將 dividend - (tmp<<1) >= 0 拆開，避免 tmp overflow
            while(dividend - tmp >= tmp) { 
                tmp <<= 1;
                mul <<= 1;
            }
            dividend -= tmp;
            quotient += mul;
        }
        return sign*quotient;
    }
};

class Solution {
    /*
        quotient simply means we can substract divisor from dividend how many times and still > 0
        for example: 10 - 3 - 3 - 3 > 0 quotient is 3
        but that is too slow to get a result from big dividend and small divisor
        so, a better way is to approach the dividend in logarithm time
        10 - 3 > 0
        10 - 6 > 0 ==> shift two times 
        10 - 12 < 0
        4 - 3 > 0 ==> shift
        
        -2^31 2^31-1
        
        32 bits
        1000...000 => -2^31
        ^        ^
        sign     32th bit  
        0111...111 => 2^31-1 
    */
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long dvd = labs(dividend), dvs = labs(divisor), quotient = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while(dvd-dvs >= 0) {
            long tmp_dvs = dvs, mul = 1;
            while( dvd - (tmp_dvs << 1) > 0) {
                tmp_dvs <<= 1;
                mul <<= 1;
            }
            dvd -= tmp_dvs;
            quotient += mul;
        }
        return sign*quotient;
    }
};

