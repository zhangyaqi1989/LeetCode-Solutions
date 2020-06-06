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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> m; // map start to i
        int n = intervals.size();
        for(int i = 0; i < n; ++i) {
            m[intervals[i].start] = i;
        }
        vector<int> ans(n, -1);
        for(int i = 0; i < n; ++i) {
            int e = intervals[i].end;
            auto it = m.lower_bound(e);
            if (it != m.end()) ans[i] = it->second;
        }
        return ans;
    }
};
