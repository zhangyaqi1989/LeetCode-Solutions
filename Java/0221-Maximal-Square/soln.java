class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        int m = matrix.length, n = matrix[0].length;
        int [][] dp = new int [m + 1][n + 1];
        int ans = 0;
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                if (matrix[i - 1][j - 1] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    ans = Math.max(ans, dp[i][j] * dp[i][j]);
                }
            }
        }
        return ans;
    }
}
