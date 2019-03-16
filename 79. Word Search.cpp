class Solution {
  /*
    DFS traverse
    Time: O(N*M*3^K)
    Space: O(MN)
  */
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!board.size()) return false;
        r = board.size();
        c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c,false));
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                visited[i][j] = true;
                if(DFS(board, word, visited, 0, i, j))
                    return true;
                visited[i][j] = false;
            }
        }
        return false;
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int r, c;
    bool DFS(vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited,
             int pos, int x, int y) {
        if(board[x][y] != word[pos]) return false;
        if(pos == word.length()-1) return true;
        for(int k=0; k<4; k++) {
            int nxt_x = x + dx[k];
            int nxt_y = y + dy[k];
            if(nxt_x >=0 && nxt_x < r && nxt_y >=0 && nxt_y < c && !visited[nxt_x][nxt_y]) {
                visited[nxt_x][nxt_y] = true;
                bool arrived = DFS(board, word, visited, pos+1, nxt_x, nxt_y);
                visited[nxt_x][nxt_y] = false;      
                if(arrived) return true;
            }
        }
        return false;
    }
};