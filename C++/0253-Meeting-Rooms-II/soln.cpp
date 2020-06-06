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
        vector<pair<int, int>> pairs;
        for(auto interval : intervals)
        {
            pairs.push_back(make_pair(interval.start, 1));
            pairs.push_back(make_pair(interval.end, 0));
        }
        sort(pairs.begin(), pairs.end());
        int cnt = 0;
        int res = 0;
        for(auto p : pairs)
        {
            if (p.second == 1)
                res = max(res, ++cnt);
            else
                --cnt;
        }
        return res;
    }
};