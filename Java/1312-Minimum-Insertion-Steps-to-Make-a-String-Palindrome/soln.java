class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int [][] dp = new int[n][n];
        for(int i = 0; i < n; ++i) Arrays.fill(dp[i], 0);
        for(int len = 2; len <= n; ++len) {
            for(int lo = 0; lo + len - 1 < n; ++lo) {
                if (s.charAt(lo) == s.charAt(lo + len - 1)) {
                    dp[lo][lo + len - 1] = dp[lo + 1][lo + len - 2];
                } else {
                    dp[lo][lo + len - 1] = 1 + Math.min(dp[lo + 1][lo + len - 1], dp[lo][lo + len - 2]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
