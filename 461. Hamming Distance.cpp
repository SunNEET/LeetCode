class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, n = x^y;
        while(n) {
            res++;
            n &= n-1; // 拿 n 跟 n-1 做 and 操作會把 right most bit 1 of n 變成 0
        }
        return res;
    }
};