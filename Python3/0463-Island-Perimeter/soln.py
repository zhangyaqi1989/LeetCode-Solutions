class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    res += 4
                    if i > 0 and grid[i - 1][j] == 1:
                        res -= 2
                    if j > 0 and grid[i][j - 1] == 1:
                        res -= 2
        return res