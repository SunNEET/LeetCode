class Solution {
    // 用BST來做可以做到O((n-k+1)logk)的複雜度, 透過維護一個指向當前BST median (每次都取(k-1)/2, 左中位數)的iterator
    // 
    // 考慮四種情況: 
    // (1) 插入時 A >= mid, C++11以後multiset遇到相同大小的元素插入會保證他排在相同元素的最後面
    // 所以我們可以保證這個情況, mid 不會改變
    // (2) 插入時 A < mid, 這會導致原本指向的 mid 向右移動, 所以 mid--, 確保指向左中位數
    // (3) 刪除時 B <= mid, 這會導致 mid 向左移動, 所以要先 mid++ 再把B移除
    // (4) 刪除時 B > mid, mid 不變, 直接刪
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(nums.size()==0) return {};
        vector<double> ans;
        multiset<int> window(nums.begin(), nums.begin()+k);
        multiset<int>::iterator mid = next(window.begin(), (k-1)/2);
        for(int i=k;i<nums.size();i++) {
            // k是偶數個就要取右邊的元素相加/2, k是奇數個就相當於是兩個自己相加/2
            
            ans.push_back((static_cast<double>(*mid) + *next(mid, (k+1)%2))/2);
            window.insert(nums[i]);
            // 右界元素插入
            if(nums[i] < *mid ) mid--;
            // 左界元素pop
            if(nums[i-k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }
        // 移動完後的最後一個window
        ans.push_back((static_cast<double>(*mid) + *next(mid, (k+1)%2))/2);
        return ans;
    }
};