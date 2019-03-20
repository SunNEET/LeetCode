class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if(!rows || !cols) return 0;
        vector<vector<unsigned int>> DP(rows, vector<unsigned int>(cols, 0));
        for(int i=0; i<rows && obstacleGrid[i][0]!=1; i++) 
            DP[i][0] = 1;
        for(int i=0; i<cols && obstacleGrid[0][i]!=1; i++) 
            DP[0][i] = 1; 
        for(int i=1; i<obstacleGrid.size(); i++) {
            for(int j=1; j<obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i][j]!=1) {
                    DP[i][j] += obstacleGrid[i-1][j] != 1 ? DP[i-1][j] : 0;
                    DP[i][j] += obstacleGrid[i][j-1] != 1 ? DP[i][j-1] : 0;
                }
            }
        }
        return DP[rows-1][cols-1];
    }
};