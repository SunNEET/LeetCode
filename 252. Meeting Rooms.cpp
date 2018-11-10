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
    /*
        solution: 安排會議室數量的簡化版，用start time sort 之後看下一個的start會不會再前一個的end之後就好
        time complexity: O(nlogn)
    */
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==1) return true;
        sort(intervals.begin(),intervals.end(), [](Interval& a, Interval& b)->bool{return a.start < b.start;});
        for(int i=1;i<(int)intervals.size();i++) {
            if(intervals[i].start < intervals[i-1].end)
                return false;
        }
        return true;
    }
};