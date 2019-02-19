class Solution {
    /*
        解法頗複雜的：
        核心概念是分別找出 nums1 和 nums2 的 partition(切割點)，使得切割點左邊的數字都less than eauql to 右邊的
        e.g. nums1: [x1, x2, x3]
             nums2: [y1, y2, y3, y4]
             以下個的切割點的例子來說，必須滿足 x2 <= y3 && y2 <= x3
             x1, x2 | x3
             y1, y2 | y3, y4
             x2 > y3 的話，代表我們 x 的切割點要往左 (而這同時也會讓 y 的切割點往右)
             y2 > x3 的話，x切割點往右，以此類推 
             我們希望合併後的左半邊的元素的總數是 (n+m+1)/2，
             +1 makes it play well for both even and odd numbers of combined elements.
        如果是total number 是奇數的話，此時答案就會是 max(x2,y2)
        是偶數的話，就是 (max(x2,y2) + min(x3,y3))/2

        Time: O(log(min(n,m))), where n is size of nums1, m is size of nums2
        Space: O(1)

        We can easily do it in O(n+m) time complexity, just keep comparing their values from their beginning
        But if it need to be done in O(log(m+n)), it's straightforward we need to perform
        binary search on a sorted list or the input data need to be a binary tree structure.
        In this case, the input data are two sorted array, so we should use binary search to
        reach this time complexity.

    */
private:

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n; // possible partition positions range from 0 to n
                          // e.g. [x1, x2, x3, x4]
                          //      ^  ^   ^   ^   ^ 
                          // there are 5 partition position for an array of size 4
        while(l<=r) {
            int partitionX = l+(r-l)/2;
            int partitionY = (n+m+1)/2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
            int minRightX = (partitionX == n) ? INT_MAX : nums1[partitionX];
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
            int minRightY = (partitionY == m) ? INT_MAX : nums2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX) {
                if((n+m)&1) {
                    return (double)max(maxLeftX, maxLeftY);
                } else {
                    return (double)(max(maxLeftX,maxLeftY)+min(minRightY,minRightX))/2;
                }
            } else if (maxLeftX > minRightY) {
                r = partitionX - 1;
            } else {
                l = partitionX + 1;
            }
        }
        return -1;
    }
};