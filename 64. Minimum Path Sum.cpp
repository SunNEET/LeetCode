class Solution {
    /*簡單棋盤DP，只能往右往下走就把第一列第一行初始化好就可以一路推出答案了*/
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size()) return -1;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> DP(rows, vector<int>(cols,0));
        DP[0][0] = grid[0][0];
        for(int i=1; i<rows; i++) DP[i][0] = DP[i-1][0]+grid[i][0];
        for(int i=1; i<cols; i++) DP[0][i] = DP[0][i-1]+grid[0][i];
        for(int i=1; i<rows; i++) {
            for(int j=1; j<cols; j++) {
                DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + grid[i][j];
            }
        }
        return DP[rows-1][cols-1];
    }
};