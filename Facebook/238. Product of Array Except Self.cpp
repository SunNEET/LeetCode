// O(n) time and O(n) space
class Solution {
    
    // 假如我們有 nums = [a,b,c,d,e] 五個數，要讓他們乘上不同的數 x[i] 後的乘積都會一樣大。
    // 直覺做法是，讓他乘起來會變成 a*b*c*d*e，因為這是個保證大家都可以乘出來的數字。
    // 而要乘出這個數自然就是用 a[i]本身 乘上 剩下的部分。
    // E.g. a[2] = c 要變成 a*b*c*d*e ，還需要乘 a*b 和 d*e，而在處理這個剩下的部分有個技巧
    // 就是用兩個 array 紀錄從左乘到右 (a*b*....) 和 從右乘到左 (e*d*.....)
    // 這樣再用一個for迴圈掃過 nums 時就把他左右兩側的乘積再乘起來就好
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> prefix(n); // prefix[i] denotes a product from nums[0] to nums[i-1]
        vector<int> suffix(n); // suffix[i] denotes a product from nums[n-i] to nums[n-1]
        prefix[0]=1;
        suffix[0]=1;
        for(int i=1;i<n;i++) {
            prefix[i] = prefix[i-1]*nums[i-1];
            suffix[i] = suffix[i-1]*nums[n-i];
        }
        for(int i=0;i<n;i++)
            ans[i] = prefix[i]*suffix[n-1-i];
        return ans;
    }
};

// O(n) time and O(1) space except the ans array
class Solution {
    // 已經知道 ans 裡每格該填什麼了，現在要做的是不用額外的空間來存 prefix 和 suffix
    // 其實就是直接維護一個 prefix 的值和一個 suffix 的值，執行 for 迴圈掃過去的時候
    // 他們分別從左右兩側往另一側移動，所以也可以看成有兩個 two pointers
    // 當prefix的 pointer 經過 nums[i] 和 suffix 的 pointer 經過 nums[n-1-i] 的時候
    // 就把目前的值乘到他們經過的位置上
    // 換句話說，一個ans[i]會先拿到他該有的 prefix 或 suffix 某一側的乘積，然後才會拿到另一側的
    // e.g nums = [a,b,c,d,e], ans are suppose to be [b*c*d*e, a*c*d*e,......, a*b*c*d]
    // 對於 ans 的第二個元素 ans[1], 他會先拿到 prefix = a, 然後把 prefix 乘上自己的value向右傳
    // 之後才有已經乘好的 suffix = c*d*e 過來乘給他
    
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


