class Solution {
    /*
        看上去挺嚇人的字串模擬，但找到 pattern 後其實不難
        把字串展開來看的話：
        Δ1 = 2n-2 Δ2 = 0            1                           2n-1                         4n-3
        Δ1 = 2n-4 Δ2 = 2            2                     2n-2  2n                    4n-4   4n-2
        Δ1 = 2n-6 Δ2 = 4            3               2n-3        2n+1              4n-5       .
        Δ1 = ...  Δ2 =              .           .               .               .            .
        Δ1 = ...  Δ2 =              .       n+2                 .           3n               .
        Δ1 = 2n-2*(i+1)             n-1 n+1                     3n-3    3n-1                 5n-5
        Δ1 = 0    Δ2 = 2n-2         n                           3n-2                         5n-4

        我們可以看出同一個 row 裡，第一個字元到下一個字元的距離會是 delta1 (跟中間斜線部分的距離)
        ，然後從位在斜線的字元往後一個字元的距離會是 delta2。
        要注意的是 row = 0 時，delta1 相當於直接跳到下一個column的距離，因為他們中間沒有其他字元
        隨著 row 變大，delta1 會越來越小，delta2會越來越大。
        到 row = numsRow-1 的時候，delta1已經沒了，但delta2就等於直接跳到下一個column的距離，
        跟 row = 0 是一樣的狀況。

        用這個規律一列一列的往下掃描，就可以建出答案了
    */
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int step1, step2;
        int len = s.size();
        string res = "";
        for(int i = 0; i < numRows; i++) {
            step1 = 2*numRows-2*(i+1);
            step2 = 2*i;
            int pos = i;
            if(pos < len) res += s[pos];
            while(1) {
                pos += step1;
                if(pos >= len) break;
                if(step1) res += s[pos];
                pos += step2;
                if(pos >= len) break;
                if(step2) res += s[pos];
            }
        }
        return res;
    }
};