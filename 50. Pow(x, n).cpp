class Solution {
    // 這題因為n太大, 用線性時間O(n)乘過一次的話會炸
    // 所以要用拆成兩份來乘, 做到O(logn)
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        // 避免2^-31出現時轉正會發生溢位
        // 用n先除2以後的t就可以避免
        int t = n/2;
        if(n<0){
            t = -t;
            x = 1/x;
        }
        // 這邊直接把n/2下去的結果存起來, 這樣就可以直接res*res
        // 而不用從頭遞回兩次
        double res = myPow(x, t);
        // 偶數直接回傳, 奇數的話要補一次方回去
        if(!(n&1)) 
            return res*res;
        else
            return res*res*x;
    }
};