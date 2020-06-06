class Solution {
    public int uniquePaths(int m, int n) {
        int dp[] = new int [n];
        dp[0] = 1;
        for(int i = 0; i < m; ++i) {
            int temp[] = new int[n];
            temp[0] = dp[0];
            for(int j = 1; j < n; ++j) {
                temp[j] = temp[j - 1] + dp[j];
            }
            dp = temp;
        }
        return dp[n - 1];
    }
}
