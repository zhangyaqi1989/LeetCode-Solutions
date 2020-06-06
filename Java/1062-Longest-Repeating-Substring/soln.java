class Solution {
    public int longestRepeatingSubstring(String S) {
        int n = S.length();
        int [][] dp = new int [n + 1][n + 1];
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if (S.charAt(i - 1) == S.charAt(j - 1)) {
                    dp[i][j] = Math.max(dp[i - 1][j - 1] + 1, dp[i][j]);
                    ans = Math.max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
}
