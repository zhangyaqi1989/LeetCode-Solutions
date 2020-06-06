class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> times;
        for(const auto & interval : intervals) {
            ++times[interval[0]];
            --times[interval[1]];
        }
        int cnt = 0;
        int mx = 0;
        for(auto & p : times) {
            cnt += p.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
};
