class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        const int kN = points.size();
        int center2 = kN % 2 ? 2 * points[kN / 2][0] : (points[kN / 2][0] + points[kN / 2 - 1][0]);
        vector<vector<int>> new_points;
        new_points.reserve(kN);
        transform(points.begin(), points.end(), back_inserter(new_points), [&](const vector<int> & point) {return vector<int>{center2 - point[0], point[1]};});
        sort(new_points.begin(), new_points.end());
        return equal(points.begin(), points.end(), new_points.begin());
    }
};
