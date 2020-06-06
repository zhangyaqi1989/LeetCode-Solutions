class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        row = 1
        while n > 0:
            if n >= row:
                n -= row
            else:
                return row - 1
            row += 1
        return row - 1
