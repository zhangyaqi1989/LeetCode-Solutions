bool mycmp(const pair<int, int> & a, const pair<int, int> & b) {
    return a.second < b.second;
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), mycmp);
        int cnt = 1, low = points[0].second;
        for(auto & point : points) {
            if (point.first > low) {
                ++cnt;
                low = point.second;
            }
        }
        return cnt;
    }
};
