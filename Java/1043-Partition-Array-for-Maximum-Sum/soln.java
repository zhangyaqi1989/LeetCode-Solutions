class Solution {
    public int maxSumAfterPartitioning(int[] A, int K) {
        int n = A.length;
        int [] dp = new int [n + 1];
        for(int i = 0; i < n; ++i) {
            int val = A[i] + dp[i];
            int mx = A[i], cnt = 1;
            for(int j = i - 1; j >= Math.max(0, i - K + 1); --j) {
                ++cnt;
                mx = Math.max(mx, A[j]);
                val = Math.max(val, mx * cnt + dp[j]);
            }
            dp[i + 1] = val;
        }
        return dp[n];
    }
}
