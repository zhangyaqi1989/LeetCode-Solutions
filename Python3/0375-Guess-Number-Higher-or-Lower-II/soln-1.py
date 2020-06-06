import functools
class Solution:
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        @functools.lru_cache(maxsize=None)
        def count(start, end):
            if start >= end:
                return 0
            return min(guess + max(count(start, guess - 1), count(guess + 1, end)) for guess in range(start, end + 1))
        return count(1, n)