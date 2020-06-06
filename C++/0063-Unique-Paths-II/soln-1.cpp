class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int R = obstacleGrid.size(), C = obstacleGrid[0].size();
        vector<vector<long long>> dp (R, vector<long long>(C, 0));
        for(int c = 0; c < C; ++c) {
            if (obstacleGrid[0][c] == 1) break;
            dp[0][c] = 1;
        }
        for(int r = 0; r < R; ++r) {
            if (obstacleGrid[r][0] == 1) break;
            dp[r][0] = 1;
        }
        for(int r = 1; r < R; ++r) {
            for(int c = 1; c < C; ++c) {
                if (obstacleGrid[r][c] == 0) {
                    dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
                }
            }
        }
        return (int) dp.back().back();
    }
};
