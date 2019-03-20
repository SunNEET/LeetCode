class Solution {
    /*
        BFS求最短路，關鍵在怎麼轉換移動到的位置到格子上
        因為他是Z字型的，所以在奇數的 row (0~N-1) 上的column會是從後面數回來的

        Time: O(N*N)
        Space: O(N*N)
    */
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if(!board.size()) return -1;
        int goal = board.size()*board.size(); // N*N
        queue<int> q;
        vector<int> dist(goal+1, INT_MAX);
        q.push(1);
        dist[1] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int k=1; k<=6; k++) {
                int nxt = cur + k;
                if(nxt > goal) break;
                pair<int,int> xy = calc(nxt, board.size());
                if(board[xy.first][xy.second] != -1)
                    nxt = board[xy.first][xy.second];
                if(dist[cur] + 1 < dist[nxt]) {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        return dist[goal] != INT_MAX ? dist[goal] : -1;
    }
private:
    pair<int,int> calc(int nxt, int n) {
        int x = (nxt-1)/n; // divided by n then we know they are in which row
        int y = (nxt-1)%n; // module by n then we know their column in a row
        if(x&1) // In odd rows, the column number grows from right to left
            y = n-1-y; 
        x = n-1-x;
        return {x,y};
    }
};