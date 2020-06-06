class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = [max(row) for row in grid]
        cols = [max(col) for col in zip(*grid)]
        return sum(max(0, min(rows[i], cols[j]) - grid[i][j]) for i in range(len(grid)) for j in range(len(grid[0])))