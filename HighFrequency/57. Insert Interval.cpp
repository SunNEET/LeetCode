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
    // 直接套用 merge interval 這題的作法
    // 先插入，然後呼叫 merge，就這樣。
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()==0) return {};
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        vector<Interval> res;
        int l = intervals[0].start;
        int r = intervals[0].end;
        for(int i=1;i<intervals.size();i++) {
            if(r >= intervals[i].start)
                r = max(r, intervals[i].end);
            else {
                res.push_back(Interval(l,r));
                l = intervals[i].start;
                r = intervals[i].end;               
            }
            if(i==intervals.size()-1)
                res.push_back(Interval(l,r));
        }
        return res;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        intervals = merge(intervals);
        return intervals;
    }
};