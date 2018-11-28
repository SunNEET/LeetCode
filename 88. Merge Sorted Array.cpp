class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        int n1p = m-1;
        int n2p = n-1;
        while(k>=0) {
            if(n1p < 0) 
                nums1[k--] = nums2[n2p--];
            else if(n2p < 0)
                nums1[k--] = nums1[n1p--];
            else {
                if(nums1[n1p] > nums2[n2p])  nums1[k--] = nums1[n1p--];
                else nums1[k--] = nums2[n2p--];
            }
        }
        return;
    }
};