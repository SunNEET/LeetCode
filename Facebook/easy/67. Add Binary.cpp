class Solution {
public:
    string addBinary(string a, string b) {
        if(!a.length() || !b.length())
            return "";
        int i = a.length()-1;
        int j = b.length()-1;
        int parity = 0;
        string ans = "";
        while(i>=0 || j>=0 || parity>0){
            int sum = 0;
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            sum += parity;
            ans += (sum%2) + '0'; // to make it become ascii's '0' and '1'
            parity = sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};