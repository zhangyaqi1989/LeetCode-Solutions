class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        // the first possible D
        double lo = 0.0, hi = 100000000.0;
        const double tol = 1e-6;
        const int n = stations.size();
        while (hi - lo > tol) {
            double mid = (lo + hi) / 2;
            int need = 0;
            for(int i = 1; i < n; ++i) {
                need += ceil((stations[i] - stations[i - 1]) / mid) - 1;
            }
            if (need > K) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
