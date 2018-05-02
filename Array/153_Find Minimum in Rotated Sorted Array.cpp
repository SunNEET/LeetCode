class Solution {
    // 找出陣列中的最小元素，無腦做就是O(N)掃過去。
    // 但這題因為有排序，只是有被rotate，整個數列其實就是被分成兩個升冪數列
    // 所以還是可以套二分搜的概念用O(logN)解決。
    // 如果區間a[end]>a[start]（沒有重複，所以不會相等），那就表示這整個這是有序的
    // 直接特判，送這個區間的起點a[start]回去

    // 在有rotate過的情況，如果a[min]>a[start]，代表最小值會在右邊的區間
    // ex: [4,5,6,7,0,1,2] => 7 > 4 => 最小元素會在[7,0,1,2]裡
    // 而如果a[min]<a[start]，那最小值一定在左邊的區間
    // ex: [7,0,1,2,4,5,6] => 2 < 7 => 最小區間會在[7,0,1,2]裡
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=(int)nums.size()-1;
        int mid;
        // 在區間大於1的時候一直砍半
        while(r-l>1) {
        	if(a[l]<a[r])
        		return a[l];
        	mid = (l+r)/2;
        	// a[mid] > a[l],表示解答會在右區間[mid,...,r]
        	if(nums[mid]>nums[l]) {
        		l = mid;
        	}
        	// a[mid] < a[l],表示解答會在左區間[l,...,mid]
        	else {
        		r = mid;
        	}
        }
        // 在這個時候會變成l+1=r
        return min(a[l],a[r]);
    }
};