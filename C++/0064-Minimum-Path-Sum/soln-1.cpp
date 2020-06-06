class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int temp = INT_MAX;
                if (i > 0 && grid[i - 1][j] < temp) temp = grid[i - 1][j];
                if (j > 0 && grid[i][j - 1] < temp) temp = grid[i][j - 1];
                if (temp != INT_MAX) grid[i][j] += temp;
            }
        }
        return grid[m - 1][n - 1];
    }
};
