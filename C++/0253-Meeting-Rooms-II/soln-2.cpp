class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> times;
        for(vector<int> & interval : intervals) {
            int s = interval[0], e = interval[1];
            ++times[s];
            --times[e];
        }
        int mx = 0, cur = 0;
        for(auto & p : times) {
            cur += p.second;
            mx = max(mx, cur);
        }
        return mx;
    }
};
