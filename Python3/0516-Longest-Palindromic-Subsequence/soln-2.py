from functools import lru_cache
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @lru_cache(None)
        def helper(lo, hi):
            if lo < hi:
                if s[lo] == s[hi]:
                    return 2 + helper(lo + 1, hi - 1)
                else:
                    return max(helper(lo + 1, hi), helper(lo, hi - 1))
            else:
                return hi - lo + 1
        return helper(0, len(s) - 1)
