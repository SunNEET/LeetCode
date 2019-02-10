class Solution {
    /*
      DFS水過
      Time: O(M*N), M is row, N is column
      Space: O(M*N), for keeping track of visit
    */
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!(int)grid.size()) return 0;
        vector<vector<short> > visited(grid.size(), vector<short>(grid[0].size(),false));
        int cnt = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    DFS(i,j,visited, grid);
                    cnt++;                    
                }
            }
        }
        return cnt;
    }
    
    void DFS(int r, int c, vector<vector<short> >& visited, vector<vector<char> >& grid) {
        visited[r][c] = true;
        for(int i=0; i<4; i++) {
            int nxt_r = r + dx[i];
            int nxt_c = c + dy[i];
            if(nxt_r >= 0 && nxt_r < grid.size() 
               && nxt_c >=0 && nxt_c < grid[0].size())
                if(!visited[nxt_r][nxt_c] && grid[nxt_r][nxt_c]=='1')
                    DFS(nxt_r,nxt_c,visited,grid);
        }
    }
};