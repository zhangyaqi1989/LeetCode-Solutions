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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> changes;
        for(auto & interval : intervals) {
            ++changes[interval.start];
            --changes[interval.end];
        }
        int cnt = 0;
        int ans = 0;
        for(auto & p : changes) {
            cnt += p.second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
