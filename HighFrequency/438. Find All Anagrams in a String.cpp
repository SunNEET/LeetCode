class Solution {
public:
    // 把 p 當作 sliding window 來做
    // 這邊的 Hash 不是單純計算兩邊的出現次數，而是對某一個字元的出現次數相差多少，也就是det
    // 只要 window 移動時 det 內部全都是 0，就表示有解
    // 壓縮 det 計算的方法
    // 先從 absSum 排除舊元素跟新元素的 det 值
    // 然後對他們的 det 分別做 -- 和 ++ 後再把他們加回absSum
    // 比方說原本有:                  變成
    // a  b  c  e                   a  b  c  e
    // 0  0 -1  1 => absSum = 2    -1  0  0  1 => absSum = 2
    // window移動後少了a, 多了c, 但因為我不想每次求absSum都要重掃一次det
    // 所以才先把這兩個從absSum裡扣掉, 把他們的det加減完後再放回去
    // 加減完再重掃一次其實是一樣意思，但要多花O(n)的時間
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int det[256]; 
        memset(det, 0, sizeof(det));
        int n = s.length(), m = p.length();
        if (n < m) return {};
        for(int i=0;i<m;i++) {
            det[s[i]]++;
            det[p[i]]--;
        }
        int absSum = 0;
        for(int i=0;i<256;i++) 
            absSum += abs(det[i]);
        if(!absSum)
            res.push_back(0);
        for(int i=m;i<n;i++) {
            int r = s[i];
            int l = s[i-m];
            absSum = absSum - abs(det[l]) - abs(det[r]);
            det[l]--;
            det[r]++;
            absSum = absSum + abs(det[l]) + abs(det[r]);
            if(!absSum)
                res.push_back(i-m+1);
        }
        return res;
    }
};