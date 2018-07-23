class Solution {
    // 先數有幾個1(cnt), 再算有幾個重疊的(rep), 周長就是cnt*4-rep*2 不難理解
    // 因為每跟一格相臨就是少掉兩條相鄰的邊
    // 另外, 為了避免重複扣, 加上我們是從左上掃到右下, 每次只要看自己的左邊跟上面就好
    // 可以當作從左上第一格開始一個陸地一個陸地填
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int r = grid.size();
        int c = grid[0].size();
        int cnt=0, rep=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j]) {
                    cnt++;
                    if( (i>0)&&(grid[i-1][j]==1) ) rep++;
                    if( (j>0)&&(grid[i][j-1]==1) ) rep++;
                }
            }
        }
        return cnt*4 - rep*2;
    }
};