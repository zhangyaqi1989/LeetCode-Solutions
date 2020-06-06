class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # as many transactions as possible
        # free - hold - cool
        if not prices: return 0
        free, hold, cool = 0, -prices[0], float('-inf')
        for price in prices[1:]:
            free, hold, cool = max(free, cool), max(hold, free - price), hold + price
        return max(free, cool)