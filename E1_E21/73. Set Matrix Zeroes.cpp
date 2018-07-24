class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size()==0) return;
        bool isR0zero = false;
        bool isC0zero = false;
        int row = matrix.size();
        int col = matrix[0].size();
        // scan col 0
        for(int i=0;i<row;i++)
            if(matrix[i][0]==0)
                isC0zero = true;
        // scan row 0
        for(int j=0;j<col;j++)
            if(matrix[0][j]==0)
                isR0zero = true;
        // 找出有0的, 然後用它們對應的第0列和第0行來記錄
        // 反正有0的話表示最後row0, col0原本的val也會被洗掉
        // 所以直接蓋上去沒關係
        for(int i=1;i<matrix.size();i++) {
            for(int j=1;j<matrix[i].size();j++) {
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 然後在掃一次, 放0
        for(int i=1;i<matrix.size();i++) {
            for(int j=1;j<matrix[i].size();j++) {
                if(matrix[i][0]==0 || matrix[0][j]==0) 
                    matrix[i][j] = 0;
            }
        }
        if(isR0zero)
            for(int j=0;j<matrix[0].size();j++)
                matrix[0][j] = 0;
        if(isC0zero)
            for(int i=0;i<matrix.size();i++)
                matrix[i][0] = 0;
        return ;
    }
};