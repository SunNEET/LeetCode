class Solution {
    // 1. 先找出第n個數是多少位數的
    // 2. 找出是哪個數
    // 3. 是哪個位置
    // * 这里首先分析一下位数和规律
    // * 个位数：1-9 (len=1, count=9 總共九個數字)
    // * 2位数：10-99 (len=2, count=90 總共180個數字)
    // * 3位数：100-999 (len=3, count=900 總共2700個數字)
    // * 4位数，1000-9999 (len=4, count=9000 總共36000個數字)
    // * 以此类推，这样我们就可以首先定位到是哪个数，再找到其对应的数字
    // 假設我們要找n=2886, 那麼2886-9-9*10*2=2697<2700
    // 得知第2886個數字會是三位數
public:
    int findNthDigit(int n) {
        int len = 1;
        long count = 9; 
        int start = 1;
        // 判斷n落在的區間
        while(n>len*count) {
            n -= len*count;
            len += 1; // 用來記錄n的位數
            count *= 10; //
            start *= 10;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n-1)%len]-'0';
    }
};