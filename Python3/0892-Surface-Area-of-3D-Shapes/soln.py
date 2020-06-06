class Solution:
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ans = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val:
                    ans += 2 + val * 4
                if i > 0 and grid[i - 1][j] > 0:
                    ans -= 2 * min(grid[i - 1][j], val)
                if j > 0 and grid[i][j - 1] > 0:
                    ans -= 2 * min(grid[i][j - 1], val)
        return ans