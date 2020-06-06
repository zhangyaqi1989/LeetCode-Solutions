class Solution:
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        return 2 * (1 + n // 2 - self.lastRemaining(n // 2))
