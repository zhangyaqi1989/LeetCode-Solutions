from functools import lru_cache
class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        @lru_cache(None)
        def fun(n):
            if n == 1:
                return 0
            elif n & 1 == 0:
                return fun(n >> 1) + 1
            else:
                return min(fun(n - 1), fun(n + 1)) + 1
        return fun(n)
