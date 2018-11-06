class Solution {
    // 判斷回文, 只考慮alphanumeric character, 可以用 isalnum
    // 大小寫當作一樣, 所以 要轉換 lower 和 upper case
    // 注意 edge case: "..", ".," ",.," "..a,", "ab ba",
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i < j) {
            if (!isalnum(s[i])) i++;
            else if (!isalnum(s[j])) j--;
            else if(tolower(s[i++])!=tolower(s[j--]))
                return false;
        }
        return true;
    }
};