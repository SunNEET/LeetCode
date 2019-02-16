class Solution {
  /*
    Key Idea: 會讓距離最短的點，就是將座標按照row和col排列的 medium (中位數)
    先理解一維的情況：
    house location: [1,6] -> best point can be anywhere between 1~6
    house location: [1,2,6] -> best point is 2, because 1 and 6 don't care where it is as long as the point is between them
    house location: [1,2,3,6] -> best point is 2.5(actually 2 or 3)
    當選擇中位數的時候，一組的左右點到中位數的距離其實就是左右相減 (R-M)+(M-L) = (R-L)

    二維其實就是一維的延伸到，分別找出所有 row 和 所有 col 的中位數
    所以實作上就是 I(row的array, 從0排到大) 一路往中位數逼近，兩個一組求出distance累加到sum上
    J(col的array)同理
  */
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(!grid.size()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> I,J;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j]==1)
                    I.push_back(i);
            }
        }
        for(int j=0; j<col; j++) {
            for(int i=0; i<row; i++) {
                if(grid[i][j]==1)
                    J.push_back(j);
            }
        }
        return minDist(I) + minDist(J);
    }
    int minDist(vector<int>& seq) {
        int i=0, j=(int)seq.size()-1, sum = 0;
        while(i < j) {
            sum += seq[j--] - seq[i++];
        }
        return sum;
    }
};

/*
補充的解釋：
I didn't read the article in your link, 
but I came up with the idea myself(Trying some 1-D special cases and then a proof by contradiction). 
Then, I wrote the code based on it, only to find it not working. 
So, I re-examined the idea, and finally figured out why it was wrong in this problem.
The reason is: In this problem, the absolute deviations at a certain position is weighted by the number of points that are actually at this position. 

If we have a bunch of coordinates, and at each coordinate, there is exactly one point, then the optimal solution is definitely the middle point. 
But now, in a single row or column, there may exist multiple points. So, the optimal solution should be biased towards the region with denser points.
As a simple example, suppose the coordinates are 0, 50 and 100. 
If there are one point at each position respectively, then the meeting point would be 50, definitely. 
But suppose there are 1000 points at 0, and other two points each at 50 and 100, respectively. 
Of course, you'll have to choose 0 as the meeting point. 
Otherwise, the 1000 points at coordinate 0 will have to move to at least 50.
*/