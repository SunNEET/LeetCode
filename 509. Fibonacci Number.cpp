class Solution {
    /*
        水題
    */
public:
    int fib(int N) {
        if(N==0) return 0;
        else if(N==1) return 1;
        vector<int> DP(N+1,0);
        DP[0]=0, DP[1]=1;
        for(int i=2; i<=N; i++) DP[i] = DP[i-1]+DP[i-2];
        return DP[N];
    }
};