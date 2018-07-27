class Solution {
    // 複習一下disjoint set, 或叫union find
    // 都是以前ACM時用的寫法, 合併時是讓p[u]->p[v]
    // 
    // 這題只要發現邊連接的兩端屬於同個set就是會變cycle了
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        for(int i=1;i<=edges.size();i++) parent[i]=i;
        for(auto e:edges) {
            int u=e[0], v=e[1];
            if(!isSameSet(findSet(u), findSet(v))) {
                Union(parent[u],parent[v]);
            } else {
                ans = e;
            }
        }
        return ans;
    }
private:
    int parent[2048];
    int findSet(int u) {
        if(parent[u]==u)
            return u;
        else
            return parent[u]=findSet(parent[u]);
    }
    void Union(int a,int b){
        int pa = findSet(a);
        int pb = findSet(b);
        if(pa!=pb){
            parent[pa]=pb;
        }
    }
    bool isSameSet(int a,int b) {
        if(parent[a]==parent[b]) 
            return true;
        else 
            return false;
    }
};