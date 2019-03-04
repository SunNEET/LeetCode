class Solution {
    /*
        題意：Solution [x0,x1,...,Xn-1] 代表數字 0,1,...,n-1 隨機出現的比率
        e.g. [1,3] 代表 0 跟 1 被 pick 的機率是 1:3
        
        為了模擬這種有權重的隨機pick，我們另外存一個 prefix sum array
        e.g. w [1,3,2,4] => wsums_[1,4,6,10]
        0,1,1,1,2,2,3,3,3,3
        ^ ^   ^ ^ ^ ^     ^
        1 2   4 5 6 7     10
        相當於把他們攤開來隨機選一個，不過實作上不會真的展開，因為這樣遇到大的權重會讓空間跟時間複雜度都上升太多
        取而代之的是，用 prefix sum array 來判斷一個 index 是落在哪個數字的範圍內
        比方說 隨機從 1~10 裡面挑一個，選到的index是 2 的話，就表示在 1 的這區

        pick 的時候可以用二分搜來加速，相當於找出這個 idx 在 wsums 中的 lower_bound
        e.g. r_idx = 4 [1,4,6,10],      r_idx = 7 [1,4,6,10]          r_idx = 0 [1,4,6,10]
                          ^lower bound                   ^lower bound            ^lower bound

        Time: O(N) for initialization, O(logN) for pickIndex
        Space: O(N)
    */
private:
    vector<int> wsums_;
public:
    Solution(vector<int> w):wsums_(w) {
        for(int i=1; i<wsums_.size(); i++)
            wsums_[i] += wsums_[i-1];
    }
    
    int pickIndex() {
        int len = wsums_.size();
        int idx = rand()%wsums_[len-1]+1; // +1?
        int left = 0, right = len - 1;
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(wsums_[mid]>idx)
                right = mid - 1;
            else if(wsums_[mid]<idx)
                left = mid + 1;
            else
                return mid;
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

class Solution {
  /*
    可以用 lower_bound 簡化成一行
  */
private:
    vector<int> wsums_;
public:
    Solution(vector<int> w):wsums_(w) {
        for(int i=1; i<wsums_.size(); i++)
            wsums_[i] += wsums_[i-1];
    }
    
    int pickIndex() {
        int len = wsums_.size();
        int idx = rand()%wsums_[len-1]+1; // +1?
        int lb = lower_bound(wsums_.begin(), wsums_.end(), idx) - wsums_.begin();
        return lb;
    }
};
