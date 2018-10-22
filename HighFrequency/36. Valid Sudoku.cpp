class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> col(9,vector<int>(9,0));
        vector<vector<int>> block(9,vector<int>(9,0));

        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                int num = board[i][j] - '1';
                if(num >= 0 && num <= 8) {
                    if(row[i][num] || col[j][num] || block[(3*(i/3)+j/3)][num]) {
                        return false;
                    } else {
                        row[i][num] = 1;
                        col[j][num] = 1;
                        block[(3*(i/3)+j/3)][num] = 1;
                    }    
                }
            }
        }
        return true;
    }
};