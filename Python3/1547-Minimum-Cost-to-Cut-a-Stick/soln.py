from functools import lru_cache
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        @lru_cache(None)
        def dp(lo, hi, s, e):
            if lo > hi:
                return 0
            else:
                cost = math.inf
                for cut_idx in range(lo, hi + 1):
                    cut = cuts[cut_idx]
                    cost = min(cost, dp(lo, cut_idx - 1, s, cuts[cut_idx]) + dp(cut_idx + 1, hi, cuts[cut_idx], e))
                cost += e - s
                return cost
        return dp(0, len(cuts) - 1, 0, n)
