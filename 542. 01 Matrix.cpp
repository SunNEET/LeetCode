class Solution {
    // 題目問每個點到0的最短距離, 但因為0本身就是0, 所以距離為0
    // 實際上會當成移動路徑的只有數值為1的點而已
    // 直覺作法是對每個1當起點做BFS,找到最近的0
    // 但這樣會TLE(如果1多又密集的話, 就會重複太多一樣的操作)

    // 所以反轉思路, 把每個0當成起點
    // 把1設成最大值, 對他們做鬆弛, 加到queue內, 一直更新到沒辦法鬆弛
    // 這樣就變成用BFS做最短路了
public:
    //四種移動方向
    vector<pair<int,int> > dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int>> zeros;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    zeros.push({i,j});
                }else{
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        // BFS最短路
        while(!zeros.empty()){
            auto xy = zeros.front();
            zeros.pop();
            int i = xy.first, j = xy.second;
            for(auto d : dir){
                int ii = i + d.first, jj = j + d.second;
                if(ii < m && ii >= 0 && jj < n && jj >= 0){
                    // 鬆弛
                    if(matrix[i][j] + 1 <= matrix[ii][jj]){
                        matrix[ii][jj] = matrix[i][j] + 1;
                        zeros.push({ii,jj});
                    }
                }
            }
        }
        return matrix;
    }
};