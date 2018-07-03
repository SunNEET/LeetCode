class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        string tmp;
        int cnt = 32;
        while(cnt--){
            tmp += std::to_string(n&1);
            n >>= 1;
        }
        for(int i=31,k=0;i>=0;i--,k++) {
            if(tmp[i]=='1')
                ans += pow(2,k);
        }
        return ans;
    }
};