from functools import lru_cache
class Solution:
    @lru_cache(None)
    def numTilings(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N <= 1:
            return 1
        elif N == 2:
            return 2
        return (2 * self.numTilings(N - 1) + self.numTilings(N - 3)) % (10 ** 9 + 7)
