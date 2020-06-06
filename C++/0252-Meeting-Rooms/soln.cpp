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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval & a, const Interval & b) 
             {return make_pair(a.start, a.end) < make_pair(b.start, b.end);});
        int low = INT_MIN;
        for (auto interval : intervals)
        {
            if (low > interval.start) return false;
            low = max(low, interval.end);
        }
        return true;
    }
};