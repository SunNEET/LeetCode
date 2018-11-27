class Solution {
    /*
        
    */
public:
    string addBinary(string a, string b) {
        string s = "";
        int sum = 0, carry = 0, i = a.length()-1, j = b.length()-1;
        while(i>=0 || j>=0 || carry==1) {
            sum += carry;
            sum += i >= 0 ? a[i--]-'0': 0;
            sum += j >= 0 ? b[j--]-'0': 0;
            s += char(sum%2 + '0');
            carry = sum/2;
            sum = 0;
        }
        reverse(s.begin(), s.end());
        return  s;
    }
};

