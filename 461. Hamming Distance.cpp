class Solution {
    // 用XOR可以秒, x^y出來的bits, 有1的部分就是x跟y不一樣的
    // 再用n&(n-1)的技巧, 一直把bits最右邊的1拿掉
    // 就可以數有幾個1在bits裡了
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int dist=0;
        while(n) {
            dist++;
            n &= (n-1);
        }
        return dist;
    }
};