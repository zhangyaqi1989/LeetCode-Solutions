class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # this is high frequency
        return sum(max(0, b - a) for a, b in zip(prices, itertools.islice(prices, 1, len(prices))))