class Solution {
    public double minmaxGasDist(int[] stations, int K) {
        int n = stations.length;
        double lo = 0.0, hi = stations[n - 1] - stations[0], mid=0, tol = 1e-6;
        while (lo + tol < hi) {
            mid = (lo + hi) / 2;
            if (valid(stations, K, mid)) hi = mid;
            else lo = mid;
        }
        return mid;
    }
    
    public boolean valid(int[] stations, int K, double D) {
        int n = stations.length;
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            cnt += Math.ceil((stations[i + 1] - stations[i]) / D) - 1;
            if (cnt > K) return false;
        }
        return true;
    }
}
