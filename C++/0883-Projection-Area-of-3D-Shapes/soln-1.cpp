class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int val = grid[i][j];
                rows[i] = max(rows[i], val);
                cols[j] = max(cols[j], val);
                ans += (val > 0);
            }
        }
        ans += accumulate(rows.begin(), rows.end(), 0) + accumulate(cols.begin(), cols.end(), 0);
        return ans;
    }
};
