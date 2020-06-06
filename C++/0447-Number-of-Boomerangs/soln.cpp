class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            map<int, int> counter;
            for(int j = 0; j < n; ++j) {
                if (i == j) continue;
                ++counter[computeDistance(points[i], points[j])];
            }
            for(auto & p : counter) {
                ans += p.second * (p.second - 1);
            }
        }
        return ans;
    }
    
    int computeDistance(pair<int, int> & p1, pair<int, int> & p2) {
        int dx = p1.first - p2.first;
        int dy = p1.second - p2.second;
        return dx * dx + dy * dy;
    }
};
