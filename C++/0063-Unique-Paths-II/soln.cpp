class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1]) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(auto j = 0; j < n; ++j)
        {
            if(obstacleGrid[0][j]) break;
            dp[0][j] = 1;
        }
        for (auto i = 0; i < m; ++i)
        {
            if(obstacleGrid[i][0]) break;
            dp[i][0] = 1;
        }
        for (auto i = 1; i < m; ++i)
            for(auto j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        return dp[m - 1][n - 1];
    }
};