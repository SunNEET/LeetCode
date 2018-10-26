// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        // If a[mid] == true, it means that the solution may be the mid, or may not.
        // The point is, we have to keep this mid, so we set r = mid;
        
        // if a[mid] == false, the solution must be on the right side of the mid 
        // [f,f,f,t,t]  [f,    t]
        //  l  mid  r   l,mid  r
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(isBadVersion(mid)) { 
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};