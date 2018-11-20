class Solution {
    /*
        就是檢查有沒有環，可以建無向圖後用 DFS 判斷
        Time Complexity: O(|V|+|E|)
    */
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++) {
            int u = edges[i].first, v = edges[i].second;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n,0);
        if(hasCycle(graph, 0, visited, -1))
            return false;
        for(int i=0;i<n;i++)
            if(!visited[i])
                return false;
        return true;
    }
    bool hasCycle(vector<vector<int>>& graph, int cur, vector<bool>& visited, int parent) {
        visited[cur] = true;
        for(int j=0;j<graph[cur].size();j++) {
            int nxt = graph[cur][j];
            if((visited[nxt] && nxt != parent) || (!visited[nxt] && hasCycle(graph,nxt,visited,cur)))
                return true;
        }
        return false;
    }
};

class Solution {
    /*
        用 Union find 判斷有沒有環，道理跟 kruskal 差不多。
        Time Complexity: O(ElogE), 
        "find" function will have an amortized time complexity of O(logE),
        if we use "path compression".
        Edges cases: (1) 非聯通塊，要檢查 edges 是否剛好為 n-1
    */
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> parent(n,-1);
        for(int i=0;i<edges.size();i++) {
            int u = edges[i].first, v = edges[i].second;
            int pu = find(u,parent);
            int pv = find(v,parent);
            if(pu == pv)
                return false;
            parent[pu] = pv;
        }
        return edges.size()==n-1;
    }
    
    int find(int v, vector<int>& parent) {
        if(parent[v]==-1)
            return v;
        return parent[v] = find(parent[v], parent);
    }
};