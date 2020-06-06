class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> xs;
        int ans = INT_MAX;
        for(const auto & point : points) {
            xs[point[0]].insert(point[1]);
        }
        for(auto i = xs.begin(); i != xs.end(); ++i) {
            for(auto j = next(i); j != xs.end(); ++j) {
                if (i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(i->second.begin(), i->second.end(),
                                j->second.begin(), j->second.end(), back_inserter(y));
                sort(y.begin(), y.end());
                const int n = y.size();
                int dx = abs(j->first - i->first);
                for(int k = 1; k < n; ++k) {
                    ans = min(ans, dx * (y[k] - y[k - 1]));
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
        
    }
};
