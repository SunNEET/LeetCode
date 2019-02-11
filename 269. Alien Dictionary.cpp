class Solution {
    /*
        Since the given words lists followed the new language order, 
        we can build a directed graph according to that, and then
        perform topological sort to produce the order
        
        關鍵就在如何實作拓墣排序而已
        流程:(1) 用 unordered_map<char,unordered_set<char>> 建圖，用 unordered_map<char,int>
            維護每個節點的 in-degree，並初始化 in-degree 成 0
            (2) for迴圈枚舉每兩個連續的字串，再用for迴圈找到不一樣的位置，建立圖的邊
            (3) 把 degree 還是 0 的加入 queue，接著就是BFS開始刪點然後同時減去連著這個點的degree
            如果變成 0 了就把 push 進 queue
            (4) 回傳結果時判斷 res 有沒有等於 degree 的大小，代表是不是 topo 有把所有點拔完加到 res 裡。
        
        坑點1: 建圖的時候要注意，一但出現一次 c1!=c2 的情況就要 break，因為排序的關係只到這邊為止
        接下來的兩個字元就沒有順序的關係了 e.g. ZAC, ZBA, 這兩個 words 的順序只能表示 A > B, 
        但 C 不見得比 A 靠前，所以必須直接 break。
        
        
    */
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,unordered_set<char> > graph;
        unordered_map<char,int> degree;
        string res = "";
        if(words.size()==0) return res;
        for(int i=0; i<words.size(); i++)
            for(int j=0; j<words[i].length(); j++)
                degree[words[i][j]] = 0;
        
        for(int i=0; i<words.size()-1; i++) {
            string cur=words[i];
            string nxt=words[i+1];
            int len = min(cur.length(), nxt.length());
            for(int j=0; j<len; j++) {
                char c1 = cur[j], c2 = nxt[j];
                if(c1!=c2) {
                    // if the goal set of c1 haven't included c2 yet, add c2 into it
                    if(!graph[c1].count(c2)) {
                        graph[c1].insert(c2);
                        degree[c2]++;
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for(auto iter=degree.begin(); iter!=degree.end(); iter++) {
            if(iter->second == 0)
                q.push(iter->first);
        }

        while(!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            if(graph.count(c)) {
                for(auto c2 : graph[c]) {
                    degree[c2]--;
                    if(degree[c2]==0)
                        q.push(c2);
                }
            }
        }
        return res.length() == degree.size() ? res : "" ;
    }
};