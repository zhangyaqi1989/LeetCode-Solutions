class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        const int R = grid.size(), C = grid[0].size();
        int ans = 0;
        for(int i = 0; i < R; ++i) {
            for(int j = 0; j < C; ++j) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
    
private:
    int dfs(vector<vector<int>> & grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;
        int old = grid[r][c];
        grid[r][c] = 0;
        int ans = max(max(dfs(grid, r - 1, c), dfs(grid, r + 1, c)), max(dfs(grid, r, c - 1), dfs(grid, r, c + 1))) + old;
        grid[r][c] = old;
        return ans;
    }
};
