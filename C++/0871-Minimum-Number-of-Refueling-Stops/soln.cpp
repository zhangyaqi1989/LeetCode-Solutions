class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> reaches;
        int i = 0;
        const int n = stations.size();
        int nfills = 0;
        int cur = 0 + startFuel;
        while (true) {
            for(;i < n; ++i) {
                if (cur >= stations[i][0]) {
                    reaches.push(stations[i][1]);
                } else break;
            }
            if (cur >= target) return nfills;
            else {
                if (reaches.empty()) return -1;
                int t = reaches.top();
                reaches.pop();
                cur += t;
                ++nfills;
            }
        }
        return nfills;
    }
};
