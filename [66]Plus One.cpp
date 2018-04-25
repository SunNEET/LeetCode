class Solution {
// 從後面直接加，然後判斷有沒有進位，很簡單
// 直接把carry初始成1就可以讓個位數也加入for迴圈的邏輯
// 不用在幫它預處理些加減進位什麼的
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1;i>=0 && carry > 0;i--) {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        }
        if (carry > 0)
            digits.insert(digits.begin(),1);
        return digits;
    }
};