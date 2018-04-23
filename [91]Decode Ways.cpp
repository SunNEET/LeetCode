class Solution {
    
int f[10000];// f[n]代表 字串s[0~n-1]有幾種分解方式
// f[n] = f[n-1](如果s[n-1]不是0) + f[n-2](如果10*s[n-2]+s[n-1]是介意10~26的數字)

public:
    int numDecodings(string s) {
        
        memset(f,0,sizeof(f));
        int len = s.length();
        if ( len == 0 || s[0] == '0' ) return 0;
        f[0]=1;
        int val = 0;
        for(int i=1;i<=len;i++){
            //當前的數字可以編碼的情況
            if(s[i-1]!='0')
                f[i] += f[i-1];
            //當前的數字+前一位數可以編碼的情況
            if(i>=2) {
                val = s[i-1]-'0' + 10*(s[i-2]-'0');
                if(val >= 10 && val <= 26)
                    f[i] += f[i-2];
            }
        }
        return f[len];
    }
};