class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        map<pair<double, double>, vector<pair<double, double>>> memo;
        sort(points.begin(), points.end());
        int n = points.size();
        for(int i = 0; i < n; ++i) {
            vector<int> & p1 = points[i];
            for(int j = i + 1; j < n; ++j) {
                vector<int> & p2 = points[j];
                // memo[{(p1[0] + p2[0]) / 2.0, (p1[1] + p2[1]) / 2.0}].push_back({p2[0] - p1[0], p2[1] - p1[1]});
                memo[{p2[0] - p1[0], p2[1] - p1[1]}].push_back({(p1[0] + p2[0]) / 2.0, (p1[1] + p2[1]) / 2.0});
            }
        }
        double ans = 1600000005.0;
        for(auto & item : memo) {
            auto vec = item.first;
            auto & lst = item.second;
            int m = lst.size();
            for(int i = 0; i < m; ++i) {
                auto & p1 = lst[i];
                for(int j = i + 1; j < m; ++j) {
                    auto & p2 = lst[j];
                    pair<double, double> perp = {p2.first - p1.first, p2.second - p1.second};
                    if (vec.first * perp.first + vec.second * perp.second == 0) {
                        double area = length(vec) * length(perp);
                        // cout << area << endl;
                        if (area < ans) ans = area;
                    }
                }
            }
        }
        
        return ans == 1600000005.0 ? 0 : ans;
    }
    double length(pair<double, double> & vec) {
        return sqrt(vec.first * vec.first + vec.second * vec.second);
    }
};
