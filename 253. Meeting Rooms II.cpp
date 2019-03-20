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
        (1) Sort the array by start time
        (2) Use a minheap to keep track of the earliest end time of each room
        (3) new room start > current earlist end time then the new meeting can just take up the original room
        (4) otherwise, we have to open a new room for them, so we push an another end time to minheap
        
    */
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(!intervals.size()) return 0;
        priority_queue<int, vector<int>, greater<int>> room;
        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs){
            return lhs.start < rhs.start;
        });
        room.push(intervals[0].end);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i].start >= room.top())
                room.pop();
            room.push(intervals[i].end);
        }
        return room.size();
    }
};