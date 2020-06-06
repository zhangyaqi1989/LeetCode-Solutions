class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        # at most k transactions
        n = len(prices)
        if 2 * k >= len(prices):
            return sum(max(0, prices[i + 1] - prices[i]) for i in range(0, n - 1))
        dp = [[0] * n for _ in range(k + 1)]
        # dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][k] + hold)
        # subproblem
        for i in range(1, k + 1):
            hold = -prices[0]
            for j in range(1, n):
                dp[i][j] = max(dp[i][j - 1], prices[j] + hold)
                hold = max(dp[i - 1][j - 1] - prices[j], hold)
        return dp[-1][-1]
