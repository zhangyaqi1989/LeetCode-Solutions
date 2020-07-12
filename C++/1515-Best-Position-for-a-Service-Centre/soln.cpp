class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 50.0, y = 50.0;
        double step = 100.0;
        const double kEps = 1e-6;
        double best = computeDistSum(positions, x, y);
        int dirs[5] = {0, 1, 0, -1, 0};
        while(step > kEps) {
            bool find = false;
            for(int k = 0; k < 4; ++k) {
                int dx = dirs[k], dy = dirs[k + 1];
                double nx = x + step * dx, ny = y + step * dy;
                double cur = computeDistSum(positions, nx, ny);
                if(cur < best) {
                    best = cur;
                    x = nx;
                    y = ny;
                    find = true;
                    break;
                }
            }
            if(!find) step /= 2.0;
        }
        return best;
    }
    
    double computeDistSum(const vector<vector<int>> & points, double x, double y) {
        double sum = 0.0;
        for(const auto & p : points) {
            sum += hypot((x - p[0]), (y - p[1]));
        }
        return sum;
    }
};
