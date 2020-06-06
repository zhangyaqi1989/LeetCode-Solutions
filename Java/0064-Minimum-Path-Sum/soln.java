class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int [] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        for(int i = 0; i < m; ++i) {
            int [] temp = new int [n];
            temp[0] = i > 0 ? dp[0] + grid[i][0] : grid[i][0];
            for(int j = 1; j < n; ++j) {
                temp[j] = grid[i][j] + Math.min(temp[j - 1], dp[j]);
            }
            dp = temp;
            // for(int j = 0; j < n; ++j) System.out.println(dp[j]);
        }
        return dp[n - 1];
    }
}
