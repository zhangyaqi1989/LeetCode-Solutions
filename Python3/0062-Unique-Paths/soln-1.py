class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # this is a dynamic programming
        dp = [1] * n
        for i in range(1, m):
            temp = dp[:]
            for j in range(1, n):
                dp[j] = dp[j - 1] + temp[j]
        return dp[-1]
        