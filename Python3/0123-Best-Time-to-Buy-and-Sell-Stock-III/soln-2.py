class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        n = len(prices)
        dp = [[0] * n for _ in range(3)]
        for i in range(1, 3):
            best_hold = -prices[0]
            for j in range(1, n):
                dp[i][j] = max(dp[i][j - 1], prices[j] + best_hold)
                best_hold = max(best_hold, dp[i - 1][j - 1] - prices[j])
        return dp[-1][-1]
