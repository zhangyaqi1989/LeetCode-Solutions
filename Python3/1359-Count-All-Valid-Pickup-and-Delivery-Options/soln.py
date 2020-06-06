from functools import lru_cache
class Solution:
    def countOrders(self, n: int) -> int:
        # left and right
        # 2n 
        # n = 1, f(n) = 1
        # n = 2, 2 * (f(n - 1) * ((n - 1) * 2 + 1))
        @lru_cache(None)
        def helper(n):
            if n == 1:
                return 1
            return n * (helper(n - 1) * ((n - 1) * 2 + 1)) % 1000000007
        return helper(n) % 1000000007
