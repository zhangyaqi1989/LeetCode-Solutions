from functools import lru_cache

class Solution:
    def minInsertions(self, s: str) -> int:
        @lru_cache(None)
        def dp(lo, hi):
            if hi - lo + 1 < 2:
                return 0
            if s[lo] == s[hi]:
                return dp(lo + 1, hi - 1)
            else:
                return 1 + min(dp(lo + 1, hi), dp(lo, hi - 1))
        return dp(0, len(s) - 1)
