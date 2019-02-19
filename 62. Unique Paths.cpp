class Solution {
    /*
        Pretty simple DP:
        Since the robot can only move right and down, when it arrives at a point, there are only two possibilities:
        (1) It arrives at that point from above (moving down to that point);
        (2) ... from left (moving right to that point).
        
        So, we have a state equation like this: dp[i][j] = dp[i-1][j] + dp[i][j-1], where dp[i][j] means the number of paths to arrive at a point (i,j).
        
        The boundary conditions of the equation occur at the leftmost column and the uppermost column.
        We can handle this by initializing the value of the first column and the first row to 1 
        as there is only one way to get to positions on the first row and the first column.
        
        Time: O(m*n)
        Space: O(m*n)
    */
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n,1));
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
    /*
        空間壓縮
        Compress the space, reduce space complexity to O(min(m,n));
        Since the value of DP[i][j] only needs dp[i-1][j] and dp[i][j-1], it is enough to maintain only two column 
        instead of maintaining the full m*n matrix.
        We can use a vector<int> called pre to record the left column, and vector<int> called cur for the current column
        the equation now become cur[i] = cur[i-1] + pre[i]
        
        Time: O(n*m)
        Space: O(min(m,n))
        
        坑點：記得要更新 pre[i]
    */
public:
    int uniquePaths(int m, int n) {
        if(m > n) uniquePaths(n,m);
        vector<int> pre(m,1);
        vector<int> cur(m,1);
        for(int j=1; j<n; j++) {
            for(int i=1; i<m; i++) {
                cur[i] = cur[i-1] + pre[i];
                pre[i] = cur[i];
            }
        }
        return cur[m-1];
    }
};