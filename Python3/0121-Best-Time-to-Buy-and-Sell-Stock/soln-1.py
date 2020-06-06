class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min_price, profit = float('inf'), 0
        for price in prices:
            min_price = min(price, min_price)
            profit = max(profit, price - min_price)
        return profit