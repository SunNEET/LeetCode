class Solution {
    /*
        基本的上色判斷，有個tip是沒訪問過的設0，兩種顏色設成 1 和 -1，這樣往下個點上色的時候可以用*(-1)來切換。

        Edge cases:
        (1) 可能是非連通圖，所以每個點都要看看能不能當起點
    */
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors((int)graph.size(),0); // 0:Haven't been colored yet/ 1:Red/ -1:Blue
        for(int i=0;i<(int)graph.size();i++) {
            if(colors[i] == 0 && !DFS(graph,colors,1,i))
                return false;
        }
        return true;
    }
    
    bool DFS(const vector<vector<int>>& graph, vector<int>& colors, int color, int node) {
        if(colors[node]!=0) // 已經上過色
            return colors[node] == color;
        colors[node] = color;
        for(int i=0;i<(int)graph[node].size();i++) {
            int nxt = graph[node][i];
            if(!DFS(graph,colors,(-1)*color,nxt))
               return false;
        }
        return true;
    }
};