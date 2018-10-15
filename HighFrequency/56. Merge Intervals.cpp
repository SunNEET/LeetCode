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
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return {};
        if(intervals.size() == 1) return intervals;
        
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start < b.start;});
        vector<Interval> res;
        int l = intervals[0].start, r = intervals[0].end;
        
        for(int i=1;i<intervals.size();i++) {
            if(r >= intervals[i].start) 
                r = max(r,intervals[i].end);
            else {
                res.push_back(Interval(l,r));
                l = intervals[i].start;
                r = intervals[i].end;
            }
            // 把最後一個輸出
            if(i==intervals.size()-1)
                res.push_back(Interval(l,r));
        }
        return res;
    }
};