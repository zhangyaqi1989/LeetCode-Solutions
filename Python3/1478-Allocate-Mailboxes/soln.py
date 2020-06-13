from functools import lru_cache
sys.setrecursionlimit(1000000000)
class Solution:
    def minDistance(self, houses: List[int], k: int) -> int:
        # minimum total distance
        # How to partition the hourses into ...
        houses.sort()
        n = len(houses)
        @lru_cache(None)
        def dp(idx, k):
            if n - idx <= k:
                return 0
            if k < 0:
                return math.inf
            if idx == n:
                return 0
            lo = idx
            best = math.inf
            for nxt in range(idx + 1, len(houses) + 1):
                # from idx to nxt - 1
                hi = nxt - 1
                place = houses[(lo + hi) >> 1]
                cost = sum(abs(houses[i] - place) for i in range(idx, nxt))
                best = min(best, dp(nxt, k - 1) + cost)
            return best
        return dp(0, k)
