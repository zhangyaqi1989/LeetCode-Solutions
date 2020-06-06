from functools import lru_cache
class Solution:
    def soupServings(self, N):
        """
        :type N: int
        :rtype: float
        """
        if N > 5000:
            return 1
        return self.helper(N, N)
    @lru_cache(None)
    def helper(self, a, b):
        if a <= 0 and b <= 0: return 0.5
        if a <= 0: return 1
        if b <= 0: return 0
        return 0.25 * (self.helper(a - 100, b) + self.helper(a - 75, b - 25)
                      + self.helper(a - 50, b - 50) + self.helper(a - 25, b - 75))

