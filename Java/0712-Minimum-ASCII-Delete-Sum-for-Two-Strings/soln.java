class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int [][] dp = new int[m + 1][n + 1];
        int acc = 0;
        for(int j = 1; j < n + 1; ++j) {
            acc += s2.charAt(j - 1);
            dp[0][j] = acc;
        }
        acc = 0;
        for(int i = 1; i < m + 1; ++i) {
            acc += s1.charAt(i - 1);
            dp[i][0] = acc;
        }
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j] + s1.charAt(i - 1), dp[i][j - 1] + s2.charAt(j - 1));
                }
            }
        }
        return dp[m][n];
    }
}
