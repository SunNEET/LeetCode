class Solution {
    // 直覺解，預處理從(0,0)到(x,y)的面積是多少，
    // 這樣要求某一塊的面積時，e.g. 左上角(x1,y1) -> 右下角(x2,y2)
    // 就可以用 (0:x2,0:y2) 的面積 - (0:x1-1,0:y2) - (0:x2,0:y1-1) + (0:x1-1,0:y1-1) 花O(1)時間求得;
    // 當面積等於k次方的時候就表示裡面都是1
    // 
    // 接著用三層 for 迴圈，分別枚舉每個 x,y 都當一次左上角的點，
    // 然後枚舉 k 當作這個square的邊長，從大試到小，這樣有解(面積等於ｋ次方)就可以直接break了
    // Time Complexity: O(N^3) n*m*k
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> area(r+1,vector<int>(c+1,0)); // area[i][j] denotes area of (0:i-1,0:j-1)
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                area[i][j] = matrix[i-1][j-1] - '0'
                             + area[i-1][j]
                             + area[i][j-1]
                             - area[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                for(int k=min(r-i+1,c-j+1);k>0;k--) {
                    int sum = area[i+k-1][j+k-1]
                            - area[i+k-1][j-1]
                            - area[i-1][j+k-1]
                            + area[i-1][j-1];
                    if(sum == k*k) {
                        ans = max(ans, sum);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
    // 用 DP[i][j] 來表示點 (i-1,j-1) 當作右下角的點的話，最大能形成多大的正方形
    // 而當前的 DP[i][j]可以由它左邊,上面和左上角的 DP 求得
    // 詳細的推導可以看圖片 DP-221.png
    // 狀態轉移寫成 DP[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1
    // Time complexity: O(N^2), n*m
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(!r) return 0;
        int c = matrix[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        int ans = 0;
        for(int i=1;i<=r;i++) {
            for(int j=1;j<=c;j++) {
                if(matrix[i-1][j-1]=='0') {
                    dp[i][j] = 0;
                } else {
                    int MIN = min(dp[i-1][j],dp[i][j-1]);
                    MIN = min(MIN,dp[i-1][j-1]);
                    dp[i][j] = MIN+1;
                    ans = max(ans, dp[i][j]*dp[i][j]);
                }
            }
        }
        return ans;
    }
};
