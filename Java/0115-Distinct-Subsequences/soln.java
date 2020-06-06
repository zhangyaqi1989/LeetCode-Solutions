class Solution {
    public int numDistinct(String s, String t) {
        int nt = t.length(), ns = s.length();
        long[][] dp = new long[nt + 1][ns + 1];
        for(int j = 0; j < ns + 1; ++j) dp[0][j] = 1;
        for(int i = 1; i < nt + 1; ++i) {
            for(int j = 1; j < ns + 1; ++j) {
                if (s.charAt(j - 1) == t.charAt(i - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return (int) dp[nt][ns];
    }
}
