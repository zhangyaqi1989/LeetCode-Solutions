from functools import lru_cache
class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        pres = [0]
        for stone in stoneValue:
            pres.append(pres[-1] + stone)
        @lru_cache(None)
        def dp(lo, hi):
            if lo == hi:
                return 0
            ans = 0
            for i in range(lo + 1, hi + 1):
                # [lo, i - 1], [i, hi]
                left = pres[i] - pres[lo]
                right = pres[hi + 1] - pres[i]
                if left == right:
                    ans = max(ans, left + max(dp(lo, i - 1), dp(i, hi)))
                elif left < right:
                    ans = max(ans, left + dp(lo, i - 1))
                else:
                    ans = max(ans, right + dp(i, hi))
            return ans
        return dp(0, len(stoneValue) - 1)
