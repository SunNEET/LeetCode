class Solution {
    // 基本的思路就是, 不是用底*高來算, 而是每個單元寬度分開看
    // 最左跟最右自然不用管, 所以只要把[1~n-1]裡的每格
    // 他能有多高的水加起來, 就是答案
    // 每格的水的高度求法: h = min(left_max,right_max) - height[i]; 淺顯易懂
    // 但直接雙層迴圈(第一層枚舉要計算高度的格子, 第二層分別找左邊最高跟右邊最高)枚舉的話, 時間複雜度會上到O(N^2)
    
    // 這邊可以用DP把到[0~i]為止, 左邊的最高值存起來
    // 以及[i~n]為止, 右邊最高的值存起來
    // 然後就可以用一個迴圈來求上面提過的式子了

    // T O(N) C O(N)
    // 有個做法可以空間也O(1),將來再研究
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int ans = 0;
        int size = (int)height.size();
        
        vector<int> left_max(size), right_max(size);
        
        // 因為左邊往右看有延續性, 所以要知道當前左邊看過去最高的
        // 只要一直check left_max[i-1]就好
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        // 右邊同理, 只是方向反過來
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        // 
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};