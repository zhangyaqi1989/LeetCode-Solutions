class Solution {
    public int maxUncrossedLines(int[] A, int[] B) {
        int na = A.length, nb = B.length;
        int [][] dp = new int[na + 1][nb + 1];
        for(int i = 1; i <= na; ++i) {
            for(int j = 1; j <= nb; ++j) {
                if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[na][nb];
    }
}
