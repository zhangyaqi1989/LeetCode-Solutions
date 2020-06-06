class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int rows[m], cols[n];
        for(int i = 0; i < m; ++i) {
            int mx = INT_MIN;
            for(int j = 0; j < n; ++j) mx = max(mx, grid[i][j]);
            rows[i] = mx;
        }
        for(int j = 0; j < n; ++j) {
            int mx = INT_MIN;
            for(int i = 0; i < m; ++i) mx = max(mx, grid[i][j]);
            cols[j] = mx;
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ans += min(rows[i], cols[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
