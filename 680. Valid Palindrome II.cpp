class Solution {
    /*
        Solution: 用 two pointer 向中央逼近，如果 l>r or 發現 the characters they point to don't match 那就跳出loop
        如果是因為l>=r跳出來的就表示不用移就是迴文了，不然就要嘗試左邊拿掉一個，右移一個看看。
        
        Time Complexity: O(s.length) = O(N) (Even in the worst case, we only check the input string S 2 times)
    */
public:
    bool validPalindrome(string s) {
        int len = s.length();
        if(len <= 2) return true;
        int left=0, right=s.length()-1; // They point to beginning and end of input string S
        while(left < right && s[left]==s[right]) {
            left++;
            right--;
        }
        if(left>=right) return true;
        // remove a left element
        if(isPalindrome(s.substr(left+1,right-left))) return true;
        // remove a right element
        if(isPalindrome(s.substr(left,right-left))) return true;
        
        return false;
    }
    
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left<right && s[left]==s[right]){
            left++;
            right--;
        }
        if(left>=right) 
            return true;
        return false;
    }
};