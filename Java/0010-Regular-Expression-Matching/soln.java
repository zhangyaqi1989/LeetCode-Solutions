class Solution {
    public boolean isMatch(String s, String p) {
        int ns = s.length(), np = p.length();
        boolean [][] dp = new boolean[ns + 1][np + 1];
        dp[0][0] = true;
        for(int j = 2; j < np + 1; j += 2) {
            if (p.charAt(j - 1) == '*' && dp[0][j - 2]) dp[0][j] = true;
        }
        for(int i = 1; i < ns + 1; ++i) {
            for(int j = 1; j < np + 1; ++j) {
                if (p.charAt(j - 1) == '.' || p.charAt(j - 1) == s.charAt(i - 1)) dp[i][j] = dp[i - 1][j - 1];
                if (p.charAt(j - 1) == '*') {
                    if (p.charAt(j - 2) != s.charAt(i - 1) && p.charAt(j - 2) != '.') dp[i][j] = dp[i][j - 2];
                    else {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[ns][np];
    }
}
