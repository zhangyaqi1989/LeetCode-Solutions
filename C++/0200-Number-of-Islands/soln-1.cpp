class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        const int kR = grid.size(), kC = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < kR; ++i) {
            for(int j = 0; j < kC; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfs(&grid, i, j);
                }
            }
        }
        return cnt;
    }

private:
    void dfs(vector<vector<char>> * grid, int r, int c) {
        const int kR = grid->size(), kC = (*grid)[0].size();
        if (0 <= r && r < kR && 0 <= c && c < kC && (*grid)[r][c] == '1') {
            (*grid)[r][c] = '0';
            dfs(grid, r - 1, c);
            dfs(grid, r + 1, c);
            dfs(grid, r, c - 1);
            dfs(grid, r, c + 1);
        }
    }
};
