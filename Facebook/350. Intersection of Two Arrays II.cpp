class Solution {
    /*
        盡可能得輸出兩邊同時都有重複到的元素 e.g. [1,2,2,1], [2,2] => [2,2]
        改用 HashMap 計算他們出現的次數(Count the number of occurence)

        Time complexity: O(n)
        Space complexity: O(n)
    */
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> cnt;
        for(int i=0; i<nums1.size(); i++) cnt[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) {
            if(cnt[nums2[i]]>0) {
                res.push_back(nums2[i]);
                cnt[nums2[i]]--;
            }
        }
        return res;
    }
};

class Solution {
    /*
        Two pointer，但前提是要兩個 array 要 sort 過。
        
    */
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1p = 0, n2p = 0;
        while(n1p < (int)nums1.size() && n2p < (int)nums2.size()) {
            if(nums1[n1p] > nums2[n2p]) n2p++;
            else if(nums1[n1p] < nums2[n2p]) n1p++;
            else {
                res.push_back(nums1[n1p]);
                n1p++; n2p++;
            }
        }
        return res;
    }
};

class Solution {
    /*
        面對一大一小的follow up: binarySearch版本
    */
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int start = 0;
        // 枚舉短的那個array，在大的那個里做二分搜，這邊假設nums1是短的，nums2是長的
        for(int i=0; i<nums1.size(); i++) {
            int idx = binarySearch(nums2, start, nums1[i]);
            if(idx!=-1) {
                res.push_back(nums1[i]);
                start = idx + 1;
            }
        }
        return res;
    }
    
    int binarySearch(vector<int> nums, int start, int target) {
        if(start >= nums.size()) return -1;
        int l = start, r = nums.size()-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid] < target) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        if(l < nums.size() && nums[l] == target)
            return l;
        return -1;
    }
};