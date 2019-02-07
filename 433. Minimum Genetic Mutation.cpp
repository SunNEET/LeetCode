class Solution {
    /*
        用 BFS 來解，從每個字串的開頭字元窮舉每種可能的變化(A,C,G,T)，並塞入到 queue 裡
        (1) 用 set 來紀錄已經訪問過的組合來剪枝，因為後面的字串變化成已經訪問過的字串
            也只會產生出前面那個字串所變化出的組合
        (2) 每層BFS的時候都先記住目前的sz是多少，只 expand 當前 layer 的狀態，push進queue的等下輪再處理
        
        *時間&空間複雜度還不太確定是不是這樣算*
        Time: O(N*M*K), N是起始字串的長度(8), M是基因字元的數量(4), K是bank裡的數量
        (1) We are generating mutations by changing each letter in start string. 
            Then, We will have O(N * M) mutations.
        (2) We will add at most O(K) mutations into queue 
            and there is no duplicate because of set
        Space: O(N*M)
    */
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end) return 0;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;
        char charSet[4] = {'A', 'C', 'T', 'G'};
        int layer = 0;
        queue<string> qs;
        qs.push(start);
        visited.insert(start);
        while(!qs.empty()) {
            int sz = (int)qs.size();
            while(sz--) {
                string curr = qs.front(); 
                qs.pop();
                if(curr==end) return layer;
                for(int i=0; i<curr.length(); i++) {
                    char old = curr[i];
                    for(int j=0; j<4; j++) {
                        curr[i] = charSet[j];
                        if(!visited.count(curr) && bankSet.count(curr)){
                            visited.insert(curr);
                            qs.push(curr);
                        }
                    }
                    curr[i] = old;
                }
            }
            layer++;
        }
        return -1;
    }
};