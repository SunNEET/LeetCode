// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
    // 採用兩邊都是閉區間的二分搜
    // 當 a[mid] < target 的時候表示目標(或目標能插入的位置, 即第一个大于等于目标值的元素位置)
    // 必定在mid右邊(因為我們是取左中位數)，所以 left = mid + 1。
    // a[mid] > target 同理
    // 終結條件是用 left > right，因為當mid是left且target<a[mid]時會讓right跑到左邊去
public:
    int guessNumber(int n) {
        int l=1,r=n; // 兩邊都取閉區間所以是[l,r]
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