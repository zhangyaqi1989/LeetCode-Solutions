class Solution:
    _dp = [0]
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # least number: dynamic programming
        dp = self._dp
        while len(dp) < n + 1:
            dp += [min(dp[-i * i] for i in range(1, int(math.sqrt(len(dp)) + 1))) + 1]
        return dp[n]