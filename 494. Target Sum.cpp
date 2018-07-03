class Solution {
    // DFS枚舉, 直覺作法 (n不大, 也才20, 所以最多2^20種組合)
    // 之後再研究DP作法
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        DFS(0,nums, ans,0,S);
        return ans;
    }
    void DFS(int idx, vector<int>& arr, int& ans,int tmp, int& target) {
        if(idx == arr.size()) {
            if(tmp == target)
                ans++;
            return;
        }
        // +
        DFS(idx+1, arr, ans, tmp+arr[idx], target);
        // -
        DFS(idx+1, arr, ans, tmp-arr[idx], target);
        return;
    }
};