from functools import lru_cache
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        
        @lru_cache(None)
        def helper(lo, hi):
            if lo >= hi:
                return 0
            return min(x + max(helper(lo, x - 1), helper(x + 1, hi)) for x in range(lo, hi))
        return helper(1, n)
