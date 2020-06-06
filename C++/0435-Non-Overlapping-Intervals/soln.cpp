/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval & lhs, const Interval & rhs) {
    if (lhs.end < rhs.end) return true;
    else return rhs.start < rhs.start;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int lo = INT_MIN, cnt = 0;
        for(auto & inter : intervals) {
            if (inter.start < lo) {
                ++cnt;
            } else {
                lo = inter.end;
            }
        }
        return cnt;
    }
    

};
