from functools import lru_cache
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.extend([0, n])
        cuts.sort()
        @lru_cache(None)
        def dp(lo, hi):
            if hi - lo <= 1:
                return 0
            ans = math.inf
            for k in range(lo + 1, hi):
                ans = min(ans, dp(lo, k) + dp(k, hi))
            return ans + cuts[hi] - cuts[lo]
        return dp(0, len(cuts) - 1)
