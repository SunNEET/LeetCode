class Solution {
    // 1. 先找出第n個數是多少位數的
    // 2. 找出是哪個數
    // 3. 是哪個位置
    // * 这里首先分析一下位数和规律
    // * 个位数：1-9 (len=1, count=9 總共9個數字)
    // * 2位数：10-99 (len=2, count=90 總共180個數字)
    // * 3位数：100-999 (len=3, count=900 總共2700個數字)
    // * 4位数，1000-9999 (len=4, count=9000 總共36000個數字)
    // * 以此类推，这样我们就可以首先定位到是哪个数，再找到其对应的数字
    // 假設我們要找n=2886, 那麼2886-9-9*10*2=2697<2700
    // 得知第2886個數字會落在100-999中
    // 由於這區域是由3個bits組成的, 所以target就是以100為起始
    // (2697-1)/3 = (int)898.xxx = 898 (代表我們要找的是這區間第898個數) 
    // => 100 + 898 = 998 (這就是target)
    // y94x96

public:
    int findNthDigit(int n) {
        int len = 1;
        long count = 9; 
        int start = 1;
        // 判斷n落在的區間
        while(n>len*count) {
            n -= len*count;
            len += 1; // 用來記錄n的位數
            count *= 10; // 每個區間"數"的數量, 乘上len就展開成"數字"的數量
            start *= 10; // 等下用來重組target用的
        }
        // target求出他是哪個"數", n/len代表他是這區間第幾個"數"
        // 減1是因為start自己算一個"數" 要把start扣掉
        // int target = start + n/len - 1;
        int target = start + (n-1)/len;
        // 判斷在target中是第幾位
        int reminder = (n-1)%len;
        string s = to_string(target);
        return s[reminder]-'0';
    }
};