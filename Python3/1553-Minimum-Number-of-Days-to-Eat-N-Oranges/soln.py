from functools import lru_cache

class Solution:
    def minDays(self, n: int) -> int:
        # Each n
        @lru_cache(None)
        def dp(left):
            if left <= 1:
                return left
            return 1 + min(left % 2 + dp(left // 2), left % 3 + dp(left // 3))
        return dp(n)
