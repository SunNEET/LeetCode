class Solution {
    /*
        Two pointer, While sum is greater than or equal to s:
        (1) Update ans with right-left+1
        (2) Now the left pointer can safely be incremented, 
            since the minimum subarray starting from this index with
            sum >= s has been achieved
        Time Complexity: O(N)
    */
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        int left = 0, right = 0, sum = 0;
        int ans = INT_MAX;
        while(right < (int)nums.size()) {
            sum += nums[right];
            while(sum >= s) {
                ans = min(ans, right-left+1);
                sum -= nums[left++];
            }
            right++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

class Solution {
    /*
        用二分搜優化查找prefix[j]-prefix[i-1] >= sum的過程
        Time complexity: O(NlogN)
    */
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> prefixSum(nums.size()+1,0);
        prefixSum[0] = 0;
        int ans = INT_MAX;
        for(int i=1;i<=nums.size();i++)
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        for(int i=1;i<=nums.size();i++) {
            /*
                Sum of nums[i~j] = prefix[j]-prefix[i-1].
                We want to find a prefix[j] such that prefix[j]-prefix[i-1] >= sum, right? We can slightly modify the inequality
                to prefix[j] >= prefix[i-1] + sum.
                Use Binary Search to look for such prefix[j];
            */
            auto lb = lower_bound(prefixSum.begin()+i,
                                 prefixSum.end(),
                                 prefixSum[i-1]+s);
            if(lb != prefixSum.end())
                ans = min(ans, static_cast<int>(lb - (prefixSum.begin() + i - 1)));
        }
        return ans==INT_MAX ? 0 : ans ;
    }
};

class Solution {
    /*
        Naive作法 先弄出前綴和在枚舉左右界
        O(N^2)
    */
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> prefixSum(nums.size(),0);
        prefixSum[0] = nums[0];
        int ans = INT_MAX;
        for(int i=1;i<nums.size();i++)
            prefixSum[i] = prefixSum[i-1] + nums[i];
        for(int i=0;i<nums.size();i++) {
            for(int j=i;j<nums.size();j++) {
                int sum = prefixSum[j]-prefixSum[i]+nums[i];
                if(sum >= s)
                    ans = min(ans,j-i+1);
            }
        }
        return ans==INT_MAX ? 0 : ans ;
    }
};