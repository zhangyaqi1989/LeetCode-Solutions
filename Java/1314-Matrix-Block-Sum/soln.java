class Solution {
    public int[][] matrixBlockSum(int[][] matrix, int K) {
        int m = matrix.length, n = matrix[0].length;
        int [][] dp = new int[m + 1][n + 1];
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int [][] ans = new int[m][n];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int lo_i = Math.max(0, i - K), lo_j = Math.max(0, j - K);
                int hi_i = Math.min(m - 1, i + K), hi_j = Math.min(n - 1, j + K);
                ans[i][j] = dp[hi_i + 1][hi_j + 1] + dp[lo_i][lo_j] - dp[lo_i][hi_j + 1] - dp[hi_i + 1][lo_j];
            }
        }
        return ans;
    }
}
