class Solution {
	// 跟上一題基本一樣,只是多了區間元素會重複的可能
	// 所以除了上一題的a[mid]<a[start]和a[mid]>a[start]這兩種情況外
	// 還要在考慮a[mid]==a[start]的可能，而這種情況沒辦法判斷最小值會在左區間還是右區間。
	// ex: [2,2,2,1,2] 和 [2,1,2,2,2] 這兩個就都是a[mid]==a[start]
	// 但1出現在兩個不同的區間，這也都是rotate會出現的結果
	// 所以，這時候不能直接砍一半找區間，只能把l(or r)一次縮小一格
	// 在繼續在新的區間[l',r]中判斷再做一次判斷。
	// 不過這作法跟KMP做字串比對是一個道理，遇到worst case的話
	// 時間複雜度會退化回O(N)
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int mid;
        while(r-l>1){
        	if(a[r]>a[l])
        		return a[l];
        	mid = (l+r)/2;
        	if(a[mid]<a[l]) {
        		r = mid;
        	} else if(a[mid]>a[l]) {
        		l = mid;
        	} else {
        		l++;
        	}
        }
        return min(a[l],a[r]);
    }
};