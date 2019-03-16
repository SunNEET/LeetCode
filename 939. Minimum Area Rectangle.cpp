class Solution {
    /*
        枚舉會位於矩形對角的兩個點(也就是x,y都不一樣的點)
        然後看他們對應的另外兩個角存不存在，存在的話就表示能圍成矩形，求面積
        
        *這種xy坐標系的圖可以用一個 map<int,set<int>> 來存某一列上有的點/某一行上有的點 
        Time: O(N^2)
        Space: O(N)
    */
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> X;
        int minarea = 40000*40000 + 1;
        
        for(auto point : points) X[point[0]].insert(point[1]);
        
        for(auto point1 : points) {
            for(auto point2 : points) {
                if(point1[0] == point2[0] || point1[1] == point2[1]) continue;
                if(X[point1[0]].count(point2[1]) && X[point2[0]].count(point1[1])) {
                    minarea = min(minarea, abs(point1[0]-point2[0])*abs(point1[1]-point2[1]));
                }
            }
        }
        return minarea != 40000*40000 + 1 ? minarea : 0;
    }
};