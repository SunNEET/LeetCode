class Solution {
    // Naive way: approaching the value x by calculating each number from 1 to x to the power of 2
    // Better way: use binary search to approach this value x
public:
    int mySqrt(int x) {
        int l=1,r=x;
        while(l<=r) {
            int mid = l+(r-l)/2;
            // Using x/mid instead of x*x
            // prevent multiply operation from overflowing
            if(mid == x/mid)
                return mid;
            else if(mid < x/mid)
                l = mid+1;
            else if(mid > x/mid)
                r = mid-1;
        }
        // IN THIS CASE, WE ARE NOT LOOKING FOR A POSITION THAT ITS VALUE is equal or greater than
        // "X/mid" such that it CAN INSERT. WE ARE LOOKING FOR A VALUE THAT IS IMMEDIATELY BEFORE THIS POSITION

        // In my binary search, when the product of mid times mid is greater than x,
        // and mid equals l, the right would get less than left.
        // This right pointer is actually what we want
        return r;
    }
};