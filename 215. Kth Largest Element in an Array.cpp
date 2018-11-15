class Solution {
    /*
        Solution: 用 min_heap / priority_queue 來處理，大小超過 K 個的時候就一直 pop 掉開頭(最小的)，
        這樣最後 heap/queue 裡剩下的元素就是這串 array 裡的前k大元素
        Time Complexity: O(n*logk)
        Edge Cases:
        (1) Is is possible that k's value is bigger than size of nums?
        (2) Is is possible that k's value is smaller than 1, like 0 and negative number?
    */
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> kth_largest;
        for(int i=0;i<nums.size();i++){
            kth_largest.push(nums[i]);
            if(kth_largest.size()>k)
                kth_largest.pop();
        }
        return kth_largest.top();
    }
};

class Solution {
    /*
        Solution: 用 quickSelect 的做法，quickSelect 就是不做完全的 quickSort
        一樣使用 quickSort 的方式以 pivot 分割成左右兩個 group，但只往會存在答案的
        那ㄧ側繼續做 partition 找答案。
        在找 Kth largest element 的情況，且 sort 是從小排到大，
        如果 partition index 右邊的 group 大小(arraySize - 1 - partition index) >= K 的話，
        代表 kth largest element 會在右邊的 group 裡；
        如果右邊的 group < K 的話，有兩種可能
         (1) 右邊剛好是 K-1 的話那 partition index 就是第 K 大的數字了
         (2) 不然的話就表示 K 會在左邊的 group

        Time Complexity: average O(N), Worst case O(N^2)
        Edge Cases: ？
    */
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums == null || nums.length() == 0) return 0;
        if(k <= 0) return 0;
        return quickSelect(nums,0,(int)nums.size()-1,k);
    }
    int quickSelect(vector<int>& nums, int left, int right, const int& k) {
        // Use last element as a pivot
        int pivot = nums[right];
        int smaller_part_index = left-1;
        int loop_index = left;
        while(loop_index < right) {
            if(nums[loop_index] <= pivot)
                swap(nums[++smaller_part_index],nums[loop_index]);
            loop_index++;
        }
        // move the pivot element back to its position
        swap(nums[right], nums[++smaller_part_index]);
        
        if((int)nums.size() - 1 - smaller_part_index >= k) 
            return quickSelect(nums,smaller_part_index+1,right,k);
        else {
            if((int)nums.size() - 1 - smaller_part_index == k-1)
                return nums[smaller_part_index];
            else
                return quickSelect(nums,left,smaller_part_index-1,k);
        }
    }
};

/* Quick Sort 複習
    選定一個 array 裡的 element 當作 pivot
    用這個 pivot 把 array 裡的元素分成小於(等於)它的和大於(等於)它的 左右兩個 group
    選 pivot 可以:
    (1) 選尾
    (2) 選頭
    (3) 選中間

    以(1)為例的話，我們用 i 來指向左側較小 group，用來填小於 pivot 的 element 的位置 (start from left-1)
    然後用 j 當作一般的 loop_variable 來掃。每當 j 看到 arr[j] <= pivot，就把它換到 i+1 (swap(arr[i+1],arr[j]))
    接著i++,j++。不然的話就不做任何事，繼續j++。結束 while loop 後把 尾巴元素(right) 跟 partition index (i+1) 互換
    至此完成一個 partition。再來就是左右遞迴做一樣的事情

    (2) 以此類推，不過照上面用 arr[j] <= pivot 當條件來 swap 的話，partition index 會是

    (3) 選中間的話比較特別，就是先把他換到區間[l,r]的最後面，然後對[l,r-1]區間裡用i,j從左右swap
    i一路往右直到遇到>pivot的值，j一路往左直到遇到<=pivot的值, swap(i,j), 當i>j的時候break, swap(i,r)
*/

