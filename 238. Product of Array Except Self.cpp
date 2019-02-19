class Solution {
    /*
        O(n) time and O(1) space except the ans array
        已經知道 ans 裡每格該填什麼了，現在要做的是不用額外的空間來存 prefix 和 suffix
        其實就是直接維護一個 prefix 的值和一個 suffix 的值，執行 for 迴圈掃過去的時候
        他們分別從左右兩側往另一側移動，所以也可以看成有兩個 two pointers
        當prefix的 pointer 經過 nums[i] 和 suffix 的 pointer 經過 nums[n-1-i] 的時候
        就把目前的值乘到他們經過的位置上
        換句話說，一個ans[i]會先拿到他該有的 prefix 或 suffix 某一側的乘積，然後才會拿到另一側的
        e.g nums = [a,b,c,d,e], ans are suppose to be [b*c*d*e, a*c*d*e,......, a*b*c*d]
        對於 ans 的第二個元素 ans[1], 他會先拿到 prefix = a, 然後把 prefix 乘上自己的value向右傳
        之後才有已經乘好的 suffix = c*d*e 過來乘給他
    */
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        int prefix=1; // prefix[i] denotes a product from nums[0] to nums[i-1]
        int suffix=1; // suffix[i] denotes a product from nums[n-i] to nums[n-1]
        for(int i=0;i<nums.size();i++) {
            ans[i] *= prefix;
            prefix *= nums[i];
            ans[n-1-i] *= suffix;
            suffix *= nums[n-1-i];
        }
        return ans;
    }
};