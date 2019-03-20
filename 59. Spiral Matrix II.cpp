class Solution {
    /*
        用跟Spiral Matrix I一樣的方式走訪圖，只是改成填數字
    */
public:
    vector<vector<int>> generateMatrix(int n) {
        int row_start = 0, row_end = n-1;
        int col_start = 0, col_end = n-1;
        int num = 1;
        vector<vector<int>> res(n, vector<int>(n,0));
        while(row_start <= row_end && col_start <= col_end) {
            // move right
            for(int col = col_start; col <= col_end; col++)
                res[row_start][col] = num++;
            row_start++;
            for(int row = row_start; row <= row_end; row++)
                res[row][col_end] = num++;
            col_end--;
            if(row_start <= row_end) {
                for(int col = col_end; col >= col_start; col--)
                    res[row_end][col] = num++;
                row_end--;
            }
            if(col_start <= col_end) {
                for(int row = row_end; row >= row_start; row--)
                    res[row][col_start] = num++;
                col_start++;
            }
        }
        return res;
    }
};