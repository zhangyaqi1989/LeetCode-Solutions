class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        # at most k
        if not prices:
            return 0
        if k * 2 >= len(prices):
            return sum(max(0, b - a) for a, b in zip(prices, prices[1:]))
        n = len(prices)
        dp = [[0] * n for _ in range(k + 1)]
        for k in range(1, k + 1):
            best_hold = -prices[0] # best profit while holding stock
            for j in range(1, n):
                dp[k][j] = max(dp[k][j - 1], prices[j] + best_hold)
                best_hold = max(best_hold, dp[k - 1][j - 1] - prices[j])
        return dp[-1][-1]
