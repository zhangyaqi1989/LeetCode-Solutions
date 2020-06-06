class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [1] + [0] * (n - 1)
        for i in range(m):
            temp = dp[:]
            dp[0] = 1 if dp[0] and obstacleGrid[i][0] != 1 else 0
            for j in range(1, n):
                dp[j] = 0 if obstacleGrid[i][j] else temp[j] + dp[j - 1]
        return dp[-1]