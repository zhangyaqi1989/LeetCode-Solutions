class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int lo = 0, hi = n - 1;
        while (lo < hi && s.charAt(lo) == s.charAt(hi)) {
            ++lo;
            --hi;
        }
        if (lo >= hi) return n;
        int [][] dp = new int[n][n];
        for(int i = 0; i < n; ++i) Arrays.fill(dp[i], 0);
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
}
