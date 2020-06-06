class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        LR, UB = [max(row) for row in grid], [max(col) for col in zip(*grid)]
        return sum(min(LR[i], UB[j]) - grid[i][j] for i in range(len(grid)) for j in range(len(grid[0])))