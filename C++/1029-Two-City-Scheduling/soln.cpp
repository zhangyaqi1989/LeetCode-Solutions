class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, int>> ps;
        int i = 0;
        for(vector<int> & ab : costs) {
            ps.emplace_back(ab[0] - ab[1], i++);
        }
        sort(ps.begin(), ps.end());
        int ans = 0, n = costs.size() / 2;
        for(int i = 0; i < ps.size(); ++i) {
            if (i < n) {
                ans += costs[ps[i].second][0];
            } else {
                ans += costs[ps[i].second][1];
            }
        }
        return ans;
    }
};
