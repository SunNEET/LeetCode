class Solution {
    /*
        2 pointer
        Time: O(N)
        Space: O(1), in-place
    */
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;
        while(left < right) {
            s[left] = s[left]^s[right];
            s[right] = s[left]^s[right];
            s[left] = s[left]^s[right];
            left++; right--;
        }
    }
};