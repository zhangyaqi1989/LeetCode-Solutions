class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        def dfs(grid, r, c):
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or not grid[r][c]:
                return
            grid[r][c] = 0
            dfs(grid, r - 1, c)
            dfs(grid, r + 1, c)
            dfs(grid, r, c - 1)
            dfs(grid, r, c + 1)
        def get_nconnects(grid):
            grid_copy = copy.deepcopy(grid)
            cnt = 0
            for i, row in enumerate(grid_copy):
                for j, val in enumerate(row):
                    if val == 1:
                        dfs(grid_copy, i, j)
                        cnt += 1
            return cnt
        cnt = get_nconnects(grid)
        if cnt != 1:
            return 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    grid[i][j] = 0
                    if get_nconnects(grid) != 1:
                        return 1
                    grid[i][j] = 1
        return 2
