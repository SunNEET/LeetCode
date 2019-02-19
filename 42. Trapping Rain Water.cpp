class Solution {
/*
    基本的思路就是, 不是用底*高來算, 而是每個單元寬度分開看
    最左跟最右自然不用管, 所以只要把[1~n-1]裡的每格
    他能有多高的水加起來, 就是答案
    每格的水的高度求法: h = min(left_max,right_max) - height[i]; 淺顯易懂
    但直接雙層迴圈(第一層枚舉要計算高度的格子, 第二層分別找左邊最高跟右邊最高)枚舉的話, 時間複雜度會上到O(N^2)
    
    這邊可以用DP把到[0~i]為止, 左邊的最高值存起來
    以及[i~n]為止, 右邊最高的值存起來
    然後就可以用一個迴圈來求上面提過的式子了

    Time: O(N)
    Space: O(N)
*/
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int ans = 0, size = (int)height.size();
        vector<int> leftmax(size), rightmax(size);
        leftmax[0] = height[0];
        for(int i=1; i<size; i++)
            leftmax[i] = max(height[i], leftmax[i-1]);
        rightmax[size-1] = height[size-1];
        for(int i=size-2; i>=0; i--)
            rightmax[i] = max(height[i], rightmax[i+1]);
        for(int i=1; i<=size-2; i++)
            ans += min(leftmax[i], rightmax[i]) - height[i];
        return ans;
    }
};


class Solution {
/*
    實際上可以不用 extra space，用 two pointer 就行了。想法很類似，一樣是一次處理一個 bit。
    當 A[left] <= A[right]，表示當前左界的高度比較矮，所以往這邊注水的話，右邊比較高或一樣高的那個，
    是一定能擋住的。有點像我們從左右一次放一個箱子進去看能 trap 住多少水
    
    Time: O(N)
    Space: O(N)
*/
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        int maxleft = 0, maxright = 0;
        while(left <= right) {
            if(height[left] <= height[right]) {
                if(height[left] >= maxleft) maxleft = height[left];
                else res += min(maxleft,height[right]) - height[left];
                left++;
            } else {
                if(height[right] >= maxright) maxright = height[right];
                else res += min(maxright,height[left]) - height[right];
                right--;
            }
        }
        return res;
    }
};
