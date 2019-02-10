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
    *非最優解*
    把 newInterval 塞進 intervals 裡，然後照 merge Interval 的做法 sort 一遍
    Time: O(nlogn)
    Space: O(n)
  */
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b)->bool{ return a.start < b.start; });
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            if(ans.back().end >= intervals[i].start)
                ans.back().end = max(ans.back().end, intervals[i].end);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};

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
        *最優解*
        Make use of the given condition to reduce the time complexity
        (1) 因為 intervals 是不重疊，且排好序的，所以插入 newInterval 的時候，
            可以先把intervals 裡 end time < new 的 start time 的都直接塞進新的 vector。
        (2) 再來就是把目前intervals的end time跟newInterval的start time有交錯的開始merge，
            直到 start time 已經超過 newInterval 的 end time就結束，因為new interval影響就只到這裡了
        (3) 把剩下的塞進ans
        Time: O(n)
        Space: O(n)
    */
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       
        vector<Interval> ans;
        int i = 0;
        // Intervals which in the left side of new Interval. No-overlap.
        while(i<intervals.size() && intervals[i].end < newInterval.start)
            ans.push_back(intervals[i++]);
        
        // overlapping with newInterval
        while(i<intervals.size() && intervals[i].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            i++;
        }
        ans.push_back(newInterval);
        // add all the rest
        while(i<intervals.size())
            ans.push_back(intervals[i++]);
        return ans;
    }
};