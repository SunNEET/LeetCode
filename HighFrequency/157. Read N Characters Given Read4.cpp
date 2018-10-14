// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    // 題目很confusing，所以用自己的話記下來
    // 1. 題目給的read4會從某個地方讀file, 並且填到你給的buffer, 然後回傳他讀了多少字元(最多4)
    // 2. 我們要做的read就是把他用read4讀的東西串起來填到buf, 然後回傳讀了多少個字元

    // 思路：用一個cnt判斷每次讀到多少字元，讀到0個就表示沒東西了，跳出while；
    // 有讀到東西就讓他從tmp[0~cnt-1]把值一個一個填給buf
    // 每填一個值 total 就 +1, 當 total 等於 n 就不能再讀了, 直接break
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0, total = 0;
        char tmp[4];
        while((cnt = read4(tmp))>0) {
            for(int i=0;i<cnt && total<n;i++) {
                buf[total++] = tmp[i];
            }
            if(total >= n)
                break;
        }
        return total;
    }
};