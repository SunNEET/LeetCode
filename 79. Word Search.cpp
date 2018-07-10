class Solution {
    // DFS枚舉就好
    // 有個小技巧是把當前格子上的char存起來, 然後改成0
    // 可以避免重複走到同一個格子, 搜索玩出來再還原
    // 這樣就不用在令一個bool array確認有沒有visited過了
    int r,c;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0) return false;
        r = (int)board.size();
        c = (int)board[0].size();
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(DFS(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, const string& word, int d, int i, int j) {
        if(i<0||j<0||i>=r||j>=c||board[i][j]!=word[d]) 
            return false;
        if(d == word.length()-1)
            return true;
        char cur = board[i][j];
        board[i][j] = 0;
        bool ret = 
            DFS(board, word, d+1, i, j+1) ||
            DFS(board, word, d+1, i+1, j) ||
            DFS(board, word, d+1, i, j-1) ||
            DFS(board, word, d+1, i-1, j) ;
        board[i][j] = cur;
        return ret;
    }
};