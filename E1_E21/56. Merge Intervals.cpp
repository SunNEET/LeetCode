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
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){return a.start < b.start;} );
        if(!intervals.size()) return {};
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++) {
            // 沒重疊就直接加
            if(ans.back().end < intervals[i].start) 
                ans.push_back(intervals[i]);
            // 有重疊的話就去修改目前區間的右界
            else 
                ans.back().end = max(ans.back().end, intervals[i].end);
        }
        return ans;
    }
};