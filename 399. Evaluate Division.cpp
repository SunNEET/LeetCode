class Solution {
    /*
        把等式的關係建成 graph
        eg. A / B = 2 的話， A -- 2 --> B, B -- 0.5 --> A
        這是因為假如我們從 A 出發到 B 的話，我會在DFS走到目標(B)的時候，
        把 B 當作 1.0，然後乘上沿路上的 edge 回去，出來的結果就是 
        A = B * 2，因為 B = 1, 所以這筆 query 實際上就是回答 A

        Time: O(Q*E), where Q is # of the queries, E is # of equations(edge)
        Space: O(2E) => O(E)
    */
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string,double>> graph;
        for(int i=0; i<equations.size(); i++) {
            string A = equations[i].first;
            string B = equations[i].second;
            graph[A][B] = values[i];
            graph[B][A] = 1/values[i];
        }
        vector<double> res;
        for(const auto& qr : queries) {
            const string& A = qr.first;
            const string& B = qr.second;
            if(!graph.count(A) || !graph.count(B)) {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double product = 1.0;
            res.push_back(divide(A, B, graph, visited, product));
        }
        return res;
    }
private:
    double divide(const string& A, const string& B, unordered_map<string, unordered_map<string,double>>& graph, unordered_set<string>& visited, double& product) {
        if(A == B) return 1.0;
        visited.insert(A);
        for(const auto& nxt : graph[A]) {
            const string& C = nxt.first;
            if(visited.count(C)) continue;
            double res = divide(C, B, graph, visited, product);
            /* only return the path product that reach the goal B*/
            if(res > 0) return res*nxt.second;
        }
        return -1.0;
    }
};

class Solution {
    /*
        用 Union find 的解法，複雜度只有 O(E)
        想法跟 graph 類似，把 A / B = k 看成圖 A -- k --> B
        這樣之後要推出 A 是多少的話就是假定 B 是 1 然後乘 k 回去就可以了
        
        要 query 的兩個點必須在同一個 group 否則他們沒辦法比較
        假如 query A / B，那就是看他們到 group root 的 product 分別會是多少，那就是 Root 往回推
        會得出的 A / B。
        
        關鍵在 union find 的變化上，parents 對應的是 pair<string, double> 型別的資料
        代表 { parent, 到這個 parent 為止的 product }。
        所以要當 A / B = k 不在同一個 group 裡要 merge 的時候，分別拿出 pA = {,} 和 pB = {,}
        照我們從B反推的規則必須把 pA 接到 pB，此時的pA.second 因為是 A 到 pA 的乘積 (= A / pA)
        pB.second 是 B 到 pB 的乘積 (= B / pB)，所以要得出 A / B = k, 
        就表示要滿足 pA.second * N (pA到pB的乘積) * (1/pB.second) (因為是逆向) = K
        得出 N = K * pB.second / pA.second
        所以就變成 parents[pA.first] = {pB.first, N}
        
        figure:
        A/pA = pA.second
        A ---> pA
                | pA/pB = N
                v
        B ---> pB
        B/pB = pB.second
               <- pB/B
    */
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, pair<string, double>> parents;
        for(int i=0; i<equations.size(); i++) {
            const string& A = equations[i].first;
            const string& B = equations[i].second;
            const double k = values[i];
            if(!parents.count(A) && !parents.count(B)) {
                parents[A] = {B, k};
                parents[B] = {B, 1};
            } else if(!parents.count(A)) {
                parents[A] = {B, k};
            } else if(!parents.count(B)) {
                parents[B] = {A, 1/k};
            } else {
                // return {'Parent node of grout of A'(pA), A by pA}
                auto pA = find(A, parents);
                // return {'Parent node of grout of B', Product from B to the parent node}
                auto pB = find(B, parents);
                // not in a same group, need merge
                if(pA != pB) 
                    parents[pA.first] = {pB.first, k/pA.second*pB.second};
            }
        }
        vector<double> res;
        for(int i=0; i<queries.size(); i++) {
            const string& A = queries[i].first;
            const string& B = queries[i].second;
            if (!parents.count(A) || !parents.count(B)) {
                res.push_back(-1.0);
                continue;
            }
            auto pA = find(A, parents);
            auto pB = find(B, parents);
            if(pA.first != pB.first) 
                res.push_back(-1.0);
            else
                res.push_back(pA.second/pB.second);
        }
        return res;
    }
    
private:
    pair<string, double> find(const string& C, unordered_map<string, pair<string,double>>& parents) {
        if(C != parents[C].first) {
            const auto p = find(parents[C].first, parents);
            parents[C].first = p.first;
            parents[C].second *= p.second;
        }
        return parents[C];
    } 
};