class Solution {
    // 暴力解法是對2~n的每個數i都判斷他能不能被除了自己跟1以外的數整除，但這樣複雜度O(N^2)
    // 但這可以進一步優化, 因為假如數i能被p整除, 那i=p*q, 且p<=q, 表示q也能整除i
    // 後半段的判斷其實就是多餘的, 所以我們只要判斷到"根號i"以前的數就好
    // (ex: 12= 1x12, 2x6, 3x4, 4x3, 6x2, 12x1, 我們只要判斷到3就好)
    
    // 最標準的是用Eratosthenes篩法(埃氏篩法)打表, 打表的時間複雜度是O(NloglogN)
    // 就是枚舉表上的質數, 然後用上面提到的優化觀念, 從2枚舉到根號i為止, 這樣剩下的就是n以內的prime了
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,true);
        // 從2開始枚舉, tricky part是用i*i<n來表達i<根號n,這樣可以避開耗時的sqrt計算和浮點數
        for(int i=2;i*i<n;i++) {
            if(isPrime[i]) {
                // j=i*i而不是i*2開始是因為, 在前面先枚舉2,3,...的時候, 就肯定踩過這些比i小的乘數了
                // 因此可以省略掉以前(i-1)的那些乘數, 用i*i當作質數往後的下一個倍數
                for(int j=i*i;j<n;j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        int cnt = 0;
        for(int i=2;i<n;i++) 
            if(isPrime[i])
                cnt++;
        return cnt;
    }
};