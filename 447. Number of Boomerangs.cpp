class Solution {
    /*
        用 point[i] 當基準點，判斷 points[j] 跟他離的距離
        如果某個距離出現過兩次以上，就滿足 boomerangs 的條件
        假如距離 point[i] 同樣是dist的點有 N 個，那能湊出的組合就是(C N 取 2) * 2 (因為可以互換位置) = n*(n-1)
        Time:  O(N^2)
        Space: O(N)
    */
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        unordered_map<int,int> cnt;
        for(int i=0; i<points.size(); i++) {
            for(int j=0; j<points.size(); j++) {
                if(i==j) continue;
                int dist = getDistance(points[i], points[j]);
                cnt[dist]++;
            }
            for(auto word_freq : cnt) {
                int freq = word_freq.second;
                res += freq*(freq-1);
            }
            cnt.clear();
        }
        return res;
    }
    int getDistance(pair<int, int>& a, pair<int, int>& b) {
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        return dx*dx + dy*dy;
    }
};