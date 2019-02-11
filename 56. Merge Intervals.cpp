class Solution {
  /*
    用 starting time 排序後，把第一個區間先塞進去
    之後就一直判斷目前res的最後一個區間的end是否 >= 目前的區間的start
    是的話就 update res.back().end
    不然就直接 push 這個區間進 res
    Time: O(nlogn)
    Space: O(n)
  */
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()==0) return res;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};