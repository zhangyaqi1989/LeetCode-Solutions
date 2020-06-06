class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> times;
        for(auto & interval : intervals) {
            int s = interval[0], e = interval[1];
            ++times[s];
            --times[e];
        }
        int cur = 0;
        int ans = 0;
        for(auto & p : times) {
            cur += p.second;
            ans = max(ans, cur);
        }
        return ans;
    }
};
