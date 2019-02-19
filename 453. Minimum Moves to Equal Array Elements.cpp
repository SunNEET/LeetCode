class Solution {
    /*
        Sorting & diff:
        直接模擬一個一個加上去的複雜度是O(n^2*k)，太慢了
        就算用找出 current largest 和 smallest 相減求 diff，一次加 diff 的方式也太慢了O(n^2)
        為了改進這個方法，我們可以先用 O(nlogn) 的時間把 nums 做 sorting
        這樣就可以用 O(1) 的時間找到最大最小值，加到最後也只需要 O(n)
        因為我們已經把 nums 排序好了，所以一開始最大最小值會在 a[0] 跟 a[n-1]
        把 diff 加到除了 a[n-1] 以外的所有元素上後，新的最大值會是a[n-2]，最小值仍舊是a[0] (以及a[n-1])
        換句話說，我們就是一直拿 a[n-i] 去減 a[0] 算出 diff，然後加到總次數上去
        而且我們也不用管先前的 diff 是多少，因為 a[0] 和其他的元素是一起加 diff 的，所以他們之間的差一直是一樣的
        
        Time: O(nlogn)
        Space: O(1)

        還有另一種也是 O(nlogn) 的 DP 解
        另外有 O(n) 的數學解
    */
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0;
        for(int i = n-1; i > 0; i--) {
            cnt += nums[i] - nums[0];
        }
        return cnt;
    }
};