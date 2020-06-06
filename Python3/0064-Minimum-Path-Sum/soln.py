class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        dp = [0] * len(grid[0])
        for j in range(n):
            dp[j] = grid[0][j] if j == 0 else dp[j - 1] + grid[0][j]
        for i in range(1, m):
            dp[0] += grid[i][0]
            temp = dp[:]
            for j in range(1, n):
                dp[j] = min(dp[j - 1], temp[j]) + grid[i][j]
        return dp[-1]