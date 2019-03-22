class Solution {
    /*
        因為問題保證A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
        所以可以用 Binary search 找出滿足A[mid-1] < A[mid] && A[mid] > A[mid+1]的mid
        如果 A[mid] < A[mid+1] 表示現在的 mid 在山峰左邊
        如果 A[mid-1] > A[mid] 表示現在的 mid 在山峰右邊
        Time: O(logN)
        Space: O(1)
    */
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size()-1, mid;
        while(l<=r) {
            mid = l+(r-l)/2;
            if(A[mid] < A[mid+1]) l = mid+1;
            else if(A[mid-1] > A[mid]) r = mid-1;
            else return mid;
        }
        return mid;
    }
};