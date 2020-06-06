class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        cnt = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == '1':
                    self.dfs(grid, i, j)
                    cnt += 1
        return cnt
        
        
    def dfs(self, grid: List[List[str]], i: int, j: int):
        if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == '1':
            grid[i][j] = '0'
            self.dfs(grid, i - 1, j);
            self.dfs(grid, i + 1, j);
            self.dfs(grid, i, j - 1);
            self.dfs(grid, i, j + 1);
