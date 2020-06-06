class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        int m = matrix.length, n = matrix[0].length;
        int [][] dp = new int [m][n];
        int mx = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (dfs(i, j, dp, matrix) > mx) {
                    mx = dfs(i, j, dp, matrix);
                }
            }
        }
        return mx;
    }
    
    public int dfs(int i, int j, int [][] dp, int [][] A) {
        if (dp[i][j] != 0) return dp[i][j];
        int mx = 0;
        if (i > 0 && A[i - 1][j] > A[i][j]) mx = Math.max(mx, dfs(i - 1, j, dp, A));
        if (i + 1 < dp.length && A[i + 1][j] > A[i][j]) mx = Math.max(mx, dfs(i + 1, j, dp, A));
        if (j > 0 && A[i][j - 1] > A[i][j]) mx = Math.max(mx, dfs(i, j - 1, dp, A));
        if (j + 1 < dp[0].length && A[i][j + 1] > A[i][j]) mx = Math.max(mx, dfs(i, j + 1, dp, A));
        dp[i][j] = mx + 1;
        return mx + 1;
    }
}
