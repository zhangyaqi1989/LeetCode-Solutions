class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        return sum(max(0, prices[i + 1] - prices[i]) for i in range(len(prices) - 1))