// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
    // 簡單的思路就是O(n^2)枚舉, 每個人都檢查是不是所有人都認識他, 然後他不認識所有人
    // 比較有效率的O(n)作法要用到兩個重要的性質
    // (1) knows(a,b) => 如果a認識b, 那a一定不是名人
    // (2) knows(a,b) => 如果a不認識b, 那b一定不是名人
    // 所以每次詢問就能排除一個人(a or b), n-1次詢問後就會只剩下一個人, 再對這個人做名人檢驗就能確定是不是名人
    // 所以实现上就是从左到右扫一遍，每次都是保留下的人和新的人做一次询问，最开始保留的人设为第0个人    
public:
    int findCelebrity(int n) {
        int celebrity = 0;
        for(int i=1;i<n;i++) {
            // 如果a認識b, 他那就一定不是名人, 換b當名人看看
            // 如果a不認識b, 那b肯定就不是名人, 但a仍有可能是, 所以繼續保留
            if(knows(celebrity, i)) {
                celebrity = i;
            }
        }
        for(int i=0;i<n;i++) {
            if(i!=celebrity && !knows(i,celebrity))
                return -1;
            if(i!=celebrity && knows(celebrity,i))
                return -1;
        }
        return celebrity;
    }
};