from functools import lru_cache
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        @lru_cache(None)
        def helper(lo, hi):
            if lo + 1 >= hi:
                return 0
            ans = math.inf
            for idx in range(lo + 1, hi):
                ans = min(ans, max(arr[lo:idx]) * max(arr[idx:hi]) + helper(lo, idx) + helper(idx, hi))
            return ans
        return helper(0, len(arr))
