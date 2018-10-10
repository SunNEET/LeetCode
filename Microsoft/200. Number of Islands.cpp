class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:    
    int numIslands(vector<vector<char>>& grid) {
        if( !(int)grid.size() ) return 0;
        int cnt = 0;
        int row = (int)grid.size();
        int col = (int)grid[0].size();
        vector<vector<bool>> checked(row, vector<bool>(col, false));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j]=='1' && !checked[i][j]) {
                    DFS(i, j, checked, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void DFS(int i, int j, vector<vector<bool>>& checked, vector<vector<char>>& grid) {
        checked[i][j] = true;
        for(int k=0;k<4;k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<(int)grid.size() && ny>=0 && ny<(int)grid[i].size()) {
                if(!checked[nx][ny] && grid[nx][ny]=='1') {
                    DFS(nx, ny, checked, grid);
                }
            }
        }
    }
};