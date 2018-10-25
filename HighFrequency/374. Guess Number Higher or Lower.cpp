// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l=1,r=n; // 兩邊都取閉區間所以是[l,r]
        // 找到目標數字X可以插入的第一個位置
        while(l<=r){ 
            int mid=l+(r-l)/2; // avoid overflow
            if(guess(mid)==1) { // mid < THE NUMBER
                l = mid+1;
            } else if(guess(mid)==-1) {
                r = mid-1;
            } else {
                return mid;
            }
        }
        return l;
    }
};