class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r0, c0, steps = 1;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    r0 = i, c0 = j;
                } else if (grid[i][j] == 0) ++steps;
            }
        }
        grid[r0][c0] = 0;
        int cnt = 0;
        helper(grid, r0, c0, 0, steps, cnt);
        return cnt;
    }
    
    void helper(vector<vector<int>> & grid, int i, int j, int cur, int steps, int & cnt) {
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] != -1) {
            if(grid[i][j] == 2 && cur == steps) ++cnt;
            else if (grid[i][j] == 0) {
                grid[i][j] = 1;
                helper(grid, i - 1, j, cur + 1, steps, cnt);
                helper(grid, i + 1, j, cur + 1, steps, cnt);
                helper(grid, i, j - 1, cur + 1, steps, cnt);
                helper(grid, i, j + 1, cur + 1, steps, cnt);
                grid[i][j] = 0;
            }
        }
    }
};
