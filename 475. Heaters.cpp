class Solution {
    // 用hl跟hr分別紀錄屋子離左右兩側火爐的最近距離
    // 再用res把每個屋子的min(hl,hr)存起來
    // 輸出res裡最大的數就是答案
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        int m = heaters.size();
        vector<int> hl(n,INT_MAX);
        vector<int> hr(n,INT_MAX);
        vector<int> res(n);
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        // 用雙指針來分別指向屋子跟火爐
        // 因為已經排序過, 可以確保從小排到大
        // 往左掃到右就是看現在的火爐有沒有在屋子的右手邊(或就在他的位置)
        // 沒有的話代表該看下一個火爐了
        // 有的話就把距離算出來
        for(int i=0, h=0;i<n && h<m;) {
            if(houses[i]<=heaters[h]) {
                hr[i] = heaters[h]-houses[i];
                i++;
            } else
                h++;
        }
        // 右到左
        for(int i=n-1,h=m-1;i>=0 && h>=0;) {
            if(houses[i]>=heaters[h]) {
                hl[i] = houses[i]-heaters[h];
                i--;
            } else
                h--;
        }
        int ans = 0;
        // 每戶到火爐的最短距離
        for(int i=0;i<n;i++) {
            res[i] = min(hl[i],hr[i]);
            ans = max(ans,res[i]);
        }
        return ans;
    }
};