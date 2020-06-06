class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        res = 0
        for p1, p2 in zip(prices, prices[1:]):
            if p2 > p1:
                res += p2 - p1
        return res