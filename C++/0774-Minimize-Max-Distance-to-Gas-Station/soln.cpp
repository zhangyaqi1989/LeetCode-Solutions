class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int n = stations.size();
        double lo = 0, hi = stations[n - 1] - stations[0];
        double tol = 1e-6;
        double mid = 0;
        while (lo + tol < hi) {
            mid = (lo + hi) / 2;
            if (valid(stations, K, mid)) hi = mid;
            else lo = mid;
        }
        return mid;
    }

    bool valid(vector<int>& stations, int K, double D) {
        int n = stations.size();
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            cnt += ceil((stations[i + 1] - stations[i]) / D) - 1;
            if (cnt > K) return false;
        }
        return true;
    }
};
