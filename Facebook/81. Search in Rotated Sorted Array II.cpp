class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r) {
            printf("%d %d\n",l,r);
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
                return true;
            // An only difference happens in some cases like [3,1,2,3,3,3,3] or [3,4,5,3,3,3,3],
            // when the nums[mid] == nums[left], and nums[mid] == nums[right]. In these cases,
            // we have no idea about the values between nums[mid] and nums[left], and nums[mid] and nums[right].
            // So, we have to move our left bound and right bound one by one to approach the possible answer.
            // [1,1,1,1,2,1,1,1] target = 2, worst case O(n)
            if(nums[mid] == nums[l] && nums[mid] == nums[r]) { 
                l++;
                r--;
            } else if(nums[mid] < nums[l]) {
                if(target > nums[mid] && target <= nums[r])
                    l = mid+1;
                else
                    r = mid-1;
            } else if(nums[mid] > nums[r]) {
                if(target < nums[mid] && target >= nums[l])
                    r = mid-1;
                else
                    l = mid+1;
            } else {
                if(target > nums[mid])
                    l = mid+1;
                else
                    r = mid-1;
            }
            printf("'%d %d\n",l,r);
        }
        return false;
    }
};