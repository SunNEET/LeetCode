class Solution {
    // 看到排序且O(logn)就肯定是二分搜，只是 array 有 rotate 過，所以需要多一些判斷
    // (1) 先比較 nums[mid] 和 nums[l]，如果 nums[mid] < nums[l]，就是有元素 rotate 到左邊，
    //     因此，nums裡的最大值會在 mid 的 左半邊。
    //     1. 如果 target > mid 且 target <= nums[r]，代表 target 就位於mid右邊的部分
    //     2. 否則的話 (target 比 nums[mid] 小 || target 比 nums[r] 還大 )，這值都只會出現在左邊
    //     - e.g [5,6,0,1,2,3,4], target=2, l=0, r=5, mid=3, 這樣的話就會是 (1)-1. 的情況
    //     - 假如同樣是上面的例子, target=0 or 5, 那都會是 (1)-2. 的情況
    // (2) nums[mid] > nums[r] 同理，nums 裡的最小值會在 mid 的 右半邊。
    //     1. 如果 target 
    // (3) 以上情形都沒發生，那就是正常做 binary search
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=(int)nums.size()-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < nums[l]) {
                if(target > nums[mid] && target <=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            } else if(nums[mid] > nums[r]) {
                if(target < nums[mid] && target >= nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            } else {
                if(target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
        }
        return -1;
    }
};