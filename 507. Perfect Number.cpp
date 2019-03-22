class Solution {
    /*
        實際除一遍 num%i 判斷是不是divisor
        然後把divisor加總到sum上就好了
    */
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int sum = 1;
        for(int i=2; i<=num/i; i++) {
            if(!(num%i)) {
                sum += i;
                if(i != num/i) sum += num/i;
            }
        }
        return sum == num;
    }
};