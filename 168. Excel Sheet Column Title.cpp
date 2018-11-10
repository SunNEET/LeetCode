class Solution {
    // solution: 實際上做的就是把 base 10 轉成 base 26, 但要注意每次mod前要-1讓數字修正到0-25
    // time complexity: O(logN)
public:
    string convertToTitle(int n) {
        // Now we can see that ABCD＝A×26³＋B×26²＋C×26¹＋D＝1×26³＋2×26²＋3×26¹＋4
        string str = "";
        while(n) {
            n--; // to make A-Z would be 0-25
            str += (n%26)+'A';
            n /= 26;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};