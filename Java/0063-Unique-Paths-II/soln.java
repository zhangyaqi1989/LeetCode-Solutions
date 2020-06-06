class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int [] dp = new int [n];
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for(int i = 0; i < m; ++i) {
            int [] temp = new int [n];
            temp[0] = obstacleGrid[i][0] == 0 ? dp[0] : 0;
            for(int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) temp[j] = 0;
                else temp[j] = temp[j - 1] + dp[j];
            }
            dp = temp;
        }
        return dp[n - 1];
    }
}
