class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> ys;
        for(auto & point : points) ys[point[0]].insert(point[1]);
        int mn = INT_MAX;
        for(auto i = ys.begin(); i != ys.end(); ++i) {
            for(auto j = next(i); j != ys.end(); ++j) {
                if (i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(begin(i->second), end(i->second), 
                                begin(j->second), end(j->second), back_inserter(y));
                int n = y.size();
                for(int k = 1; k < n; ++k) {
                    mn = min(mn, abs(i->first - j->first) * (y[k] - y[k - 1]));
                }
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
};
