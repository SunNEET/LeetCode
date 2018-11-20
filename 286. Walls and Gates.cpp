class Solution {
    /*
        用BFS把圖掃一遍，遇到能鬆弛的點就更新然後放進 queue
    */
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int r = rooms.size();
        if(r == 0) return;
        int c = rooms[0].size();
        queue<pair<int,int>> q;
        pair<int,int> dirs[4] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(rooms[i][j]==0)
                    q.push(make_pair(i,j));
            }
        }
        while(!q.empty()) {
            int curR = q.front().first, curC = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nxtR = curR + dirs[i].first, nxtC = curC + dirs[i].second;
                if(nxtR >= 0 && nxtR < r && nxtC >=0 && nxtC < c
                   && rooms[curR][curC]+1 < rooms[nxtR][nxtC] ) {
                    rooms[nxtR][nxtC] = rooms[curR][curC]+1;
                    q.push(make_pair(nxtR, nxtC));
                }
            }
        }
        return;
    }
};