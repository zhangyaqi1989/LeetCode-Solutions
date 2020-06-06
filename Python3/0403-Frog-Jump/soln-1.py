from functools import lru_cache
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        @lru_cache(None)
        def helper(pos, k):
            n = len(stones)
            for i in range(pos + 1, n):
                gap = stones[i] - stones[pos]
                if gap < k - 1:
                    continue
                elif gap > k + 1:
                    return False
                else:
                    if helper(i, gap):
                        return True
            return pos == n - 1
        return helper(0, 0)
