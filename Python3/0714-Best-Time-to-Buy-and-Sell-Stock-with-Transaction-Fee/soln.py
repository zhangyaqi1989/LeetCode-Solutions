class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        # two states: one is hold, one is free
        hold = -prices[0]
        free = 0
        for price in prices[1:]:
            hold, free = max(hold, free - price), max(free, hold + price - fee)
        return free