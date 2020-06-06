class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        map<pair<double, double>, vector<pair<double, double>>> vectors;
        const int kN = points.size();
        for(int i = 0; i < kN; ++i) {
            for(int j = i + 1; j < kN; ++j) {
                double mid_x = 0.5 * (points[i][0] + points[j][0]);
                double mid_y = 0.5 * (points[i][1] + points[j][1]);
                vectors[{points[i][0] - points[j][0], points[i][1] - points[j][1]}].emplace_back(mid_x, mid_y);
            }
        }
        double mn_area = DBL_MAX;
        for(auto & p : vectors) {
            auto v1x = p.first.first;
            auto v1y = p.first.second;
            auto & mids = p.second;
            const int kM = mids.size();
            for(int i = 0; i < kM; ++i) {
                for(int j = i + 1; j < kM; ++j) {
                    double v2x = mids[j].first - mids[i].first;
                    double v2y = mids[j].second - mids[i].second;
                    if (v2x * v1x + v1y * v2y == 0) {
                        double a = v1x * v1x + v1y * v1y;
                        double b = v2x * v2x + v2y * v2y;
                        mn_area = min(mn_area, sqrt(a * b));
                    }
                }
            }
        }
        return mn_area == DBL_MAX ? 0.0 : mn_area;
    }
};
