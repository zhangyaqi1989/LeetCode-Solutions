class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # DP problem
        if not grid or not grid[0]:
            return 0
        dp = [grid[0][0]]
        for num in grid[0][1:]:
            dp.append(dp[-1] + num)
        m, n = len(grid), len(grid[0])
        for i in range(1, m):
            temp = dp[:]
            dp[0] += grid[i][0]
            for j in range(1, n):
                dp[j] = min(temp[j], dp[j - 1]) + grid[i][j]
        return dp[-1]