class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        hold, not_hold = float('-inf'), 0
        for price in prices:
            hold, not_hold = max(hold, not_hold - price), max(not_hold, hold + price - fee)
        return not_hold