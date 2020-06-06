class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        min_seen = float('inf')
        res = 0
        for price in prices:
            res = max(price - min_seen, res)
            if price < min_seen:
                min_seen = price
        return res