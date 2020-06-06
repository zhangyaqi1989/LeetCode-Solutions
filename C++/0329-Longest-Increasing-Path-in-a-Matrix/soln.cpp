class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int mx = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                mx = max(mx, dfs(i, j, dp, matrix));
            }
        }
        return mx;
    }
    
    int dfs(int i, int j, vector<vector<int>> & dp, vector<vector<int>> & matrix) {
        if (dp[i][j] != 0) return dp[i][j];
        int mx = 0;
        if (i > 0 && matrix[i - 1][j] > matrix[i][j]) mx = max(mx, dfs(i - 1, j, dp, matrix));
        if (j > 0 && matrix[i][j - 1] > matrix[i][j]) mx = max(mx, dfs(i, j - 1, dp, matrix));
        if (i + 1 < dp.size() && matrix[i + 1][j] > matrix[i][j]) mx = max(mx, dfs(i + 1, j, dp, matrix));
        if (j + 1 < dp[0].size() && matrix[i][j + 1] > matrix[i][j]) mx = max(mx, dfs(i, j + 1, dp, matrix));
        dp[i][j] = mx + 1;
        return mx + 1;
    }
};
