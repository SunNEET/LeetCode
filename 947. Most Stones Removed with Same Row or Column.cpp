class Solution {
    /*
        把在同一列或行上的石頭視為連通圖，在上面跑 DFS。
        
        我們可以按照題目的規則(各種轉彎)一次走完一個連通圖，
        所以一個連通圖能移除的節點數就是 total_node-1 (最後會剩一個沒辦法移除的)
        換句話說，答案就是所有 stone 的數量 - 聯通塊 的數量

        Time: O(N)
        Space: O(N)
    */
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rgraph, cgraph;
        for(auto stone : stones) {
            rgraph[stone[0]].push_back(stone[1]);
            cgraph[stone[1]].push_back(stone[0]);
        }
        set<pair<int,int>> visited;
        int connect_graph_cnt = 0;
        for(auto stone : stones) {
            if(!visited.count({stone[0], stone[1]})) {
                visited.insert({stone[0], stone[1]});
                DFS(rgraph, cgraph, visited, stone[0], stone[1]);
                connect_graph_cnt++;
            }
        }
        return stones.size() - connect_graph_cnt;
    }
private:
    void DFS(unordered_map<int, vector<int>>& rgraph, 
             unordered_map<int, vector<int>>& cgraph,
             set<pair<int,int>>& visited, int cur_r, int cur_c) {
        for(auto nxt_c : rgraph[cur_r]) {
            if(!visited.count({cur_r, nxt_c})) {
                visited.insert({cur_r, nxt_c});
                DFS(rgraph, cgraph, visited, cur_r, nxt_c);
            }
        }
        for(auto nxt_r : cgraph[cur_c]) {
            if(!visited.count({nxt_r, cur_c})) {
                visited.insert({nxt_r, cur_c});
                DFS(rgraph, cgraph, visited, nxt_r, cur_c);
            }
        }
    }
};