class Solution {
    // 關鍵在於 the result of num1[i]*num2[j] will be placed at indices [i+j, i+j+1]
    // 根據這個規則就可以對兩個數的任意位數做乘法並把結果加到正確的位置
    // Time complexity: O(n*m) 
    // Edge cases: 
    // (1) 乘出來是一堆0 e.g. "9999" * "0" 要輸出 "0" 而不是 "0000"，
    //     需要在把結果拼回字串時判斷會不會造成 leading zero。
    // (2) Try something bigger than 2^32-1
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        vector<int> pos(n+m,0);
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int p1 = i+j, p2 = i+j+1;
                int sum = mul + pos[p2];
                pos[p1] += (sum)/10;
                pos[p2] = (sum)%10;
            }
        }
        string res = "";
        for(int i=0;i<pos.size();i++) {
            if(pos[i]!=0 || res.length()>0)
                res += pos[i] + '0';
        }
        return res.length()==0 ? "0" : res;
    }
};