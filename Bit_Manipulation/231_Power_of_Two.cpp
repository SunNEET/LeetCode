class Solution {
    // 2的n次方看成2進位就只會有1個1
    // 用這個想法做就好了
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        bool has_one = false;
        while(n>0) {
            if(n & 1) {
                if(has_one){
                    has_one = false;
                    break;
                } else {
                    has_one = true;    
                }
            }
            n >>= 1;
        }
        return has_one;
    }
};
