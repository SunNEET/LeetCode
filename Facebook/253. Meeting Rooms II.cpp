/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
    // 先把 meeting 用 start 時間從小到大排序，因為 meeting 就是照時間順序一個一個來的
    // 再來用 priority queue 存 meeting 的 end time，這樣就可以知道哪個 meeting 會最先結束
    // 如果這場meeting的開始時間還比會最先結束的早，那就必須分配新的office
    // 如果比較晚的話，就相當於裡面的人出來後，然後新的 meeting 就繼續用那間辦公室
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)->bool
             { return a.start < b.start; });
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<intervals.size();i++) {
            if(pq.empty())
                pq.push(intervals[i].end);
            else {
                if(intervals[i].start >= pq.top())
                    pq.pop();
                pq.push(intervals[i].end);
            }
        }
        return pq.size();
    }
};