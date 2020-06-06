class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> x_to_ys;
        for(vector<int> & point : points) x_to_ys[point[0]].insert(point[1]);
        int min_area = INT_MAX;
        for(vector<int> & p1 : points) {
            for(vector<int> & p2 : points) {
                int x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
                if (x1 == x2 || y1 == y2) continue;
                if (x_to_ys[x1].find(y2) != x_to_ys[x1].end() && x_to_ys[x2].find(y1) != x_to_ys[x2].end()) {
                    min_area = min(min_area, abs(x2 - x1) * abs(y2 - y1));
                }
            }
        }
        return min_area == INT_MAX ? 0 : min_area;
    }
};
