from functools import lru_cache
class Solution:
    def mergeStones(self, stones: List[int], K: int) -> int:
        @lru_cache(None)
        def merge(lo, hi, piles):
            if lo == hi and piles == 1:
                return 0
            if (hi - lo + 1 - piles) % (K - 1) != 0:
                return math.inf
            if piles == 1:
                return merge(lo, hi, K) + prefix[hi + 1] - prefix[lo]
            else:
                ans = math.inf
                for i in range(lo, hi, K - 1):
                    ans = min(ans, merge(lo, i, 1) + merge(i + 1, hi, piles - 1))
                return ans
                
        n = len(stones)
        if (n - 1) % (K - 1) != 0:
            return -1
        prefix = [0]
        for num in stones:
            prefix.append(prefix[-1] + num)
        ans = merge(0, n - 1, 1)
        return ans
