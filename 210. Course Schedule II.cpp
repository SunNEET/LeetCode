class Solution {
    // 有前後順序關係的有向圖，自然想到能用 topological sort 來解
    // 根據 prerequisite 和 course 的關係建圖，並且維護 incoming degree for each node
    // 把 incoming degree 是 0 的放入 BFS queue 當作起點
    // 透過變數 visCnt 維護填入答案的位置 和 是不是所有課都上得到
    
    // edge cases: 
    // (1) 最後的三元運算子判斷要 return 空 array 時要回傳一個空的vector - vector<int>({})
    // 而不能直接回傳 {} (不清楚原因)
    // (2) duplicate edges?
    // (3) 
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> incDegree(numCourses);
        vector<int> res(numCourses);
        for(auto edge : prerequisites) {
            int course = edge.first;
            int prerq = edge.second;
            graph[prerq].push_back(course);
            incDegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<incDegree.size();i++) {
            if(incDegree[i] == 0)
                q.push(i);
        }
        int visCnt = 0;
        while(!q.empty()) {
            int from = q.front();
            q.pop();
            res[visCnt++] = from;
            for(int i=0;i<(int)graph[from].size();i++) {
                int to = graph[from][i];
                incDegree[to]--;
                if(incDegree[to]==0)
                    q.push(to);
            }
        }
        return (visCnt == numCourses) ? res : vector<int>({});
    }
};