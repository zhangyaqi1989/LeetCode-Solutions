class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (vector<int> & A : points) {
            map<pair<int, int>, int> slopes;
            int x0 = A[0], y0 = A[1];
            int nsames = 0;
            int ninfs = 0;
            for(vector<int> & point : points) {
                int x1 = point[0], y1 = point[1];
                if (x0 == x1 and y0 == y1) {
                    ++nsames;
                } else if (x0 == x1) {
                    ++ninfs;
                } else {
                    int dy = y1 - y0, dx = x1 - x0;
                    int g = __gcd(dy, dx);
                    ++slopes[{dx / g, dy / g}];
                }
            }
            int mx = ninfs;
            for(auto & p : slopes) {
                if (p.second > mx) mx = p.second;
            }
            if (mx + nsames > ans) ans = mx + nsames; 
        }
        return ans;
    }
};
