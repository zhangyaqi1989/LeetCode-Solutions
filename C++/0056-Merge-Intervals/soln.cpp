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
        vector<Interval> s;
        sort(intervals.begin(), intervals.end(), [] (const Interval & a, const Interval & b) -> bool 
             {return make_pair(a.start, a.end) < make_pair(b.start, b.end);});
        for (auto interval : intervals)
        {
            int start = interval.start;
            int end = interval.end;
            if (s.empty() || start > s[s.size() - 1].end)
                s.push_back(interval);
            else
            {
                Interval top = s[s.size() - 1];
                s.pop_back();
                s.push_back(Interval(top.start, max(top.end, end)));
            }
        }
        return s;
    }
    
};