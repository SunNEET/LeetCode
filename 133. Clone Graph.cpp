/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    /*
        題目是說需要完整拷貝一份 graph，也就是要有一組新的nodes，然後他們之間的relation要跟原本的graph一樣
        把圖走一遍用DFS或BFS都可以，在要 push 他的 neighbor 進新的 node 時一路往這些 node 遞迴下去。
        這題最 tricky 的地方是沒特別做判斷的話，一個 node 可能會被 deep copy 超過一次。

        因此，我們需要用一個方式來紀錄，這個 node 是否已經被 copy 過了，同時記住新 copy 出來的點。
        我們可以靠 map 做到這件事。
        用原本的 UndirectedGraphNode* 當作 key，然後新 copy 出來的 node 當作 value，
        這樣在走訪原本的圖時就可以 
        (1) 判斷一個 node 有沒有 copy 過 
        (2) 順便判斷一個 node 有沒有走訪過 (因為第一次走訪才會還沒 copy)
        
    */
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        if(mp.count(node)==0){
            mp[node] = new UndirectedGraphNode(node->label);
            for(auto nbNode : node->neighbors) {
                mp[node]->neighbors.push_back(cloneGraph(nbNode));
            }
        }
        return mp[node];
    }
};