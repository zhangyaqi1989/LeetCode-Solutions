from functools import lru_cache
class Solution:
    def encode(self, s: str) -> str:
        @lru_cache(None)
        def helper(s):
            if not s:
                return s
            i = (s + s).find(s, 1)
            n = len(s)
            one = "{:d}[{:s}]".format(n // i, helper(s[:i])) if i < n else s
            mults =  [helper(s[:i]) + helper(s[i:]) for i in range(1, n)]
            return min([one, s] + mults, key=len)
        return helper(s)
