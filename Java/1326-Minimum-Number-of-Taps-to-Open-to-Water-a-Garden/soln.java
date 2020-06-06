class Solution {
    public int minTaps(int n, int[] ranges) {
        final int Inf = n + 100;
        int [] dp = new int [n + 1];
        Arrays.fill(dp, Inf);
        for(int i = 0; i < n + 1; ++i) {
            int left = Math.max(0, i - ranges[i]);
            int best = i - ranges[i] > 0 ? dp[left] + 1 : 1;
            for(int j = i; j < Math.min(n + 1, i + ranges[i] + 1); ++j) {
                dp[j] = Math.min(dp[j], best);
            }
        }
        return dp[n] == Inf ? -1 : dp[n];
    }
}
