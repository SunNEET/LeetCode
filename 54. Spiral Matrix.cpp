class Solution {
    /*
        簡單模擬，設定 row_begin, row_end, col_begin 和 col_end 四個變數
        模擬右下左上的移動順序，一邊縮小範圍。 坑：左跟上必須注意邊界是否已經出界
    */
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(!matrix.size() || !matrix[0].size()) return res;
        int row_begin = 0, row_end = matrix.size()-1;
        int col_begin = 0, col_end = matrix[0].size()-1;
        while(row_begin <= row_end && col_begin <= col_end) {
            for(int col = col_begin; col <= col_end; col++) 
                res.push_back(matrix[row_begin][col]);
            row_begin++;
            for(int row = row_begin; row <= row_end; row++)
                res.push_back(matrix[row][col_end]);
            col_end--;
            if(row_begin <= row_end) {
                for(int col = col_end; col >= col_begin; col--)
                    res.push_back(matrix[row_end][col]);
                row_end--;
            }
            if(col_begin <= col_end) {
                for(int row = row_end; row >= row_begin; row--)
                    res.push_back(matrix[row][col_begin]);
                col_begin++;
            }
        }
        return res;
    }
};