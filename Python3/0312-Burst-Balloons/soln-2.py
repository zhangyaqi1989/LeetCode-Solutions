from functools import lru_cache
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        coins = [1] + nums + [1]
        @lru_cache(None)
        def helper(lo, hi):
            if lo + 1 >= hi:
                return 0
            else:
                return max(coins[lo] * coins[last] * coins[hi] + helper(lo, last) + helper(last, hi) for last in range(lo + 1, hi))
        return helper(0, len(coins) - 1)
