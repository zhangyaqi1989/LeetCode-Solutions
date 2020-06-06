from functools import lru_cache
class Solution:
    def minCut(self, s: str) -> int:
        # minimum cut
        n = len(s)
        valids = set()
        for i in range(n):
            for l, r in (i, i), (i, i + 1):
                while l >= 0 and r < n and s[l] == s[r]:
                    valids.add((l, r))
                    l -= 1
                    r += 1
        @lru_cache(None)
        def helper(idx):
            if idx == len(s):
                return 0
            ans = len(s)
            for hi in range(idx, len(s)):
                if (idx, hi) in valids:
                    ans = min(ans, helper(hi + 1) + 1)
            return ans
        if not s:
            return 0
        return helper(0) - 1
