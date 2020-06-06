class Solution:
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n == 0:
            return 0
        if k >= n // 2:
            return sum(max(0, prices[i + 1] - prices[i]) for i in range(n - 1))
        dp = [[0] * n for _ in range(k + 1)]
        for i in range(1, k + 1):
            mx = -prices[0]
            for j in range(1, n):
                dp[i][j] = max(dp[i][j - 1], prices[j] + mx)
                mx = max(mx, dp[i - 1][j - 1] - prices[j])
        return dp[-1][-1]