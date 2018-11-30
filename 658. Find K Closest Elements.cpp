class Solution {
    /*
        PriorityQueue: 建個有 x 和 dist 的 struct，然後overload <，dist一樣大的話回傳 x 小的。
        dist 就是自己的位置到 x 的距離

        Time: O(nlogk)
        Space: O(k)
    */
    struct Point {
        int x;
        int dist;
        Point(int _x, int _dist): x(_x), dist(_dist) {}
        bool operator< (const Point& _p) const {
            if(this->dist == _p.dist) {
                return this->x < _p.x;
            }
            return this->dist < _p.dist;
        }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<Point> pq;
        vector<int> res;
        for(int i=0; i<arr.size(); i++) {
            Point cur(arr[i], abs(arr[i]-x));
            if(pq.size() < k) pq.push(cur);
            else {
                pq.push(cur);
                pq.pop();
            }
        }
        while(!pq.empty()) {
            res.push_back(pq.top().x);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};

class Solution {
    /*
        Binary Search: 先用BS找出 <= x 的位置，l = r++ (用來分開)，然後讓它做 k 次擴張。
        每次擴張就看 l 跟 r 誰指向的元素離 x 比較近
        Time: O(k+logn)
        Space: O(N);
    */
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int l = 0, r = arr.size()-1;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if (arr[mid] == x) { r = mid; break; } 
            else if (arr[mid] > x) r = mid - 1;
            else l = mid + 1; 
        }
        l = r++;
        while(k--) {
            if(r >= arr.size() || (l >= 0 && x-arr[l] <= arr[r]-x)) l--;
            else r++;
        }
        for(int i = l+1; i<r; i++) 
            res.push_back(arr[i]);
        return res;
    }
};