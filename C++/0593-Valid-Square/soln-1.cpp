class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // whether four points can construct a square
        vector<vector<int>> points = {p1, p2, p3, p4};
        map<int, int> distances;
        for(int i = 0; i < 4; ++i) {
            for(int j = i + 1; j < 4; ++j) {
                ++distances[(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])];
            }
        }
        return distances.size() == 2 && (*distances.begin()).first * 2 == (*distances.rbegin()).first;
    }
};
