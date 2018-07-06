class Solution {
    // DFS直接搜...沒什麼難度
    // 連接的定義就是上下左右相鄰, 不包含斜的
    // 遇到LC奇怪的OJ結果跟我跑出的code不一樣, 所以幫checked加個clear看看...
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> checked;
        checked.resize(row);
        for(int i=0;i<row;i++){
            checked[i].resize(col);
            checked[i].clear();
        }
            
        int cnt = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !checked[i][j]) {
                    DFS(i,j,checked,grid,row,col);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    void DFS(int i, int j, vector<vector<bool>>& checked, vector<vector<char>>& grid, int& row, int& col){
        if(grid[i][j]=='1'){
            checked[i][j] = 1;
            if(i-1>=0 && !checked[i-1][j])
                DFS(i-1,j,checked,grid,row,col);
            if(i+1<row && !checked[i+1][j])
                DFS(i+1,j,checked,grid,row,col);
            if(j-1>=0 && !checked[i][j-1])
                DFS(i,j-1,checked,grid,row,col);
            if(j+1>=0 && !checked[i][j+1])
                DFS(i,j+1,checked,grid,row,col);            
        }
    }
};