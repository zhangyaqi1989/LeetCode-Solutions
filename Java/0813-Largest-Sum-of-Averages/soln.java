class Solution {
    public double[][] memo;
    public double largestSumOfAverages(int[] A, int K) {
        memo = new double[120][120];
        for(double [] row : memo) Arrays.fill(row, 0);
        return helper(A, A.length, K);
    }
    
    public double helper(int[] A, int n, int K) {
        if (memo[n][K] > 0) return memo[n][K];
        double ans = 0.0;
        if (n == K || K == 1) {
            for(int i = 0; i < n; ++i) ans += A[i];
            if (K == 1) ans /= n;
            memo[n][K] = ans;
            return ans;
        }
        double cur = 0;
        int cnt = 0;
        for(int i = n - 1; i >= K - 1; --i) {
            cur += A[i];
            ++cnt;
            double temp = helper(A, i, K - 1) + cur / cnt;
            ans = Math.max(ans, temp);
        }
        memo[n][K] = ans;
        return ans;
    }
}
