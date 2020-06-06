from functools import lru_cache
MOD = 1000000007
class Solution:
    def countOrders(self, num: int) -> int:
        @lru_cache(None)
        def f(n):
            if n == 1:
                return 1
            return n * ((2 * (n - 1) + 1) * f(n - 1)) % MOD
        return f(num)
