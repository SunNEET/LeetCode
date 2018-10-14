// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    // 讓這三個變數存在於函數外，才能保存上一次讀了東西但沒用完的狀態 
    // ex: read(buf,6) 讀 [1,2,3,4,5,6,7,8], 第二次讀完 tmp中還會剩[,,7,8]
    // 此時的cur_pos還是指著tmp[2]的位置, final_pos沒做read4的話也不會改變
    int cur_pos=0, final_pos=0;
    char tmp[4];
    
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        for(int i=0;i<n;i++) {
            if(cur_pos == final_pos) {
                final_pos = read4(tmp);
                cur_pos = 0;
            }
            if(cur_pos < final_pos) 
                buf[i] = tmp[cur_pos++];
            // 上面read4讀不到東西了
            if(cur_pos == 0 && final_pos == 0)
                return i;
        }
        return n;
    }
};