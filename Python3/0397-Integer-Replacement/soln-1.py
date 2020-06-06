from functools import lru_cache
class Solution:
    @lru_cache(None)
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 0
        else:
            if n & 1 == 1:
                return 1 + min(self.integerReplacement(n + 1), self.integerReplacement(n - 1))
            else:
                return 1 + self.integerReplacement(n // 2)
