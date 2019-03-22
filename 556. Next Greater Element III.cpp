class Solution {
    /*
        基本上就是 31. Next_Permutation
        不過要處理的特例比較多, 像是沒有 next_perm()的情況就直接回傳 -1
        如果會 overflow 32-bit 的 integer 也 return -1
    */
public:
    int nextGreaterElement(int n) {
        string num;
        num = to_string(n);
        int target_idx = num.length()-1;
        int greater_min_idx = num.length()-1;
        while(target_idx > 0 && num[target_idx-1] >= num[target_idx]) 
            target_idx--;
        if(target_idx > 0) {
            target_idx--;
            while(num[greater_min_idx] <= num[target_idx]) 
                greater_min_idx--;
            swap(num[greater_min_idx], num[target_idx]);
        } else {
            return -1;
        }
        for(int left=target_idx+1, right=num.length()-1; left<right; left++, right--)
            swap(num[left], num[right]);
        int res = 0;
        for(int i=0; i<num.length();i++) {
            if(res > INT_MAX/10) return -1;
            res *= 10;
            if(res > INT_MAX - num[i] - '0') return -1;
            res += num[i] - '0';
        }
        return res;
    }
};