from functools import lru_cache
class Solution:
    def strangePrinter(self, s: str) -> int:
        @lru_cache(None)
        def helper(lo, hi):
            if lo >= hi:
                return hi - lo + 1
            ans = helper(lo + 1, hi) + 1
            for k in range(lo + 1, hi + 1):
                if s[lo] == s[k]:
                    ans = min(ans, helper(lo, k - 1) + helper(k + 1, hi))
            return ans
        return helper(0, len(s) - 1)
