class Solution(object):
    def maxKilledEnemies(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not any(grid):
            return 0
        m, n = len(grid), len(grid[0])
        rowhits = 0
        ans = 0
        colhits = [0] * n
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if j == 0 or grid[i][j - 1] == 'W':
                    rowhits = 0
                    k = j
                    while k < n and grid[i][k] != 'W':
                        rowhits += (grid[i][k] == 'E')
                        k += 1
                if i == 0 or grid[i - 1][j] == 'W':
                    colhits[j] = 0
                    k = i
                    while k < m and grid[k][j] != 'W':
                        colhits[j] += (grid[k][j] == 'E')
                        k += 1
                if val == '0':
                    ans = max(ans, rowhits + colhits[j])
        return ans