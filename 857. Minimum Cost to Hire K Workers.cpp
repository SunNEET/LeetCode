class Solution {
    /*
        Very Hard Problem: 如果要同時考慮不同 workers 間的 qualities 比率再算 wage 會讓邏輯變得很複雜。
        
        有個想法可以幫助我們簡化問題，把 quality 和 wage 的關係看成:
        每個工人都有一個自己對 wage/quality 的看法，代表他們覺得每 quality 應該值多少工資。
        雇用 K 個工人的時候，必須滿足每個人的實際 wage/quality 不低於他們的期望，換句話說，
        我們得用 K 個人中最高的 wage/quality 期望來當標準，付給全部 K 個人工資。
        舉例來說，group 裡有個 quality=1, wage=8 的工人，他的 w/q ratio 是最高的，而有另一個
        quality=10, wage=2 的工人覺得他這樣都能領這麼多，那他也要照這種比率來支付，所以我們得
        付給他 2*(8/1) 也就是 80 的工資。 (因為反過來的話，用較低的 w/q 去付給其他人，會沒辦法滿足他們的最低 wage)
        
        也因此，如果想要最小化總工資的話，我們用 greedy 的方式，從有最小比率的K個人開始看，
        用那 K 個人之中的最大 w/q 的乘上這K個人的總quality。然後將下個比率大一點的人加進group，
        並把目前 group 裡的，有最大 quality 的人去除，因為他的 w/q 比不會影響這個 group，
        是由目前最大的，也就是新進來的那個人決定的。此時移除 quality 最大的可以省下最多錢。
        
        Time: O(NlogN), due to sorting.
        Space: O(N)
        
        FAQ:
        Question: "However, it is possible that current worker has the highest quality, so you removed his quality in the last step, which leads to the problem that you are "using his ratio without him".
        Answer: It doesn't matter. The same group will be calculated earlier with smaller ratio.
    */
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double,int>> workers; // {w/q, q}
        for(int i=0; i<quality.size(); i++) 
            workers.emplace_back(1.0*wage[i]/quality[i], quality[i]);
        sort(workers.begin(), workers.end());
        int qsum = 0;
        double res = DBL_MAX;
        priority_queue<int> pq; // only maintain quantity
        for(int i=0; i<workers.size(); i++) {
            qsum += workers[i].second;
            pq.push(workers[i].second);
            if(pq.size() > K) {
                qsum -= pq.top();
                pq.pop();
            }
            if(pq.size() == K) {
                res = min(res, workers[i].first*qsum);
            }
        }
        return res;
    }
};