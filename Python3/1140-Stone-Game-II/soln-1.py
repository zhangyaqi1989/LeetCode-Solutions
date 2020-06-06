from functools import lru_cache
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        prefix = [0]
        for stone in piles:
            prefix.append(prefix[-1] + stone)
        @lru_cache(None)
        def helper(lo, M):
            if lo == len(piles):
                return 0
            ans = 0
            for i in range(lo + 1, min(lo + 2 * M + 1, len(piles) + 1)):
                # pick lo : i
                X = i - lo
                ans = max(ans, prefix[len(piles)] - prefix[lo] - helper(i, max(X, M)))
            return ans
        return helper(0, 1)
