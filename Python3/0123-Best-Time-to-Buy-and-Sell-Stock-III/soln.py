class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # maintain several states
        release1 = release2 = 0
        hold1 = hold2 = float('-inf')
        for price in prices:
            release1 = max(release1, hold1 + price)
            hold1 = max(hold1, -price)
            release2 = max(release2, hold2 + price)
            hold2 = max(hold2, release1 - price)
        return release2