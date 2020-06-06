class Solution {
    public String minWindow(String S, String T) {
        int ns = S.length(), nt = T.length();
        int [][] dp = new int[nt + 1][ns + 1];
        for(int i = 0; i < nt + 1; ++i) Arrays.fill(dp[i], -1);
        for(int j = 0; j < ns + 1; ++j) dp[0][j] = j;
        for(int i = 1; i < nt + 1; ++i) {
            for(int j = 1; j < ns + 1; ++j) {
                if (T.charAt(i - 1) == S.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        int start = 0, len = ns + 1;
        for(int j = 0; j < ns + 1; ++j) {
            if (dp[nt][j] != -1) {
                if (j - dp[nt][j] < len || (j - dp[nt][j] == len && dp[nt][j] < start)) {
                    start = dp[nt][j];
                    len = j - dp[nt][j];
                }
            }
        }
        return len == ns + 1 ? "" : S.substring(start, start + len);
    }
}
