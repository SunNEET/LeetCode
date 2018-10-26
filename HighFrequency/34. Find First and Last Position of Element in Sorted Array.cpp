class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l=0,r=nums.size()-1;
        // 靠兩次二分來分別找左右的分界線
        // 找第一次出現target的位置，所以當a[mid]>=target的時候，都把右界縮小(因為==代表可能左邊還有target)
        bool finded = false;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(nums[mid]==target)
                finded = true;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        if(finded)
            ans.push_back(l);
        else
            ans.push_back(-1);
        l=0, r=nums.size()-1;
        
        // 找最後一次target的位置，所以當a[mid]<=target的時候，都把左界右移
        // 所以left最後會落在target的右邊
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid] <= target)
                l = mid+1;
            else
                r = mid-1;
        }
        if(finded)
            ans.push_back(l-1);
        else
            ans.push_back(-1);
        return ans;
    }
};