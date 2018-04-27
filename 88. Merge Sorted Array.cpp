class Solution {
    // 因為已經排序好了，所以用兩個index分別比較兩個array的值，然後一邊移動index
    // 這題必須由後往前掃，因為題目要求直接把nums2合到nums1上，從前面放的話會蓋掉nums1原本的值
    // 要注意的點是i,j,k的edge case
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(k>=0) {
            //nums1見底了,不繼續比(會爆),無腦填nums2,反之亦然
            if(i<0) {
                nums1[k--] = nums2[j--];
            } else if(j<0) {
                nums1[k--] = nums1[i--];
            } else {
                if(nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }    
            }
        }
    }
};