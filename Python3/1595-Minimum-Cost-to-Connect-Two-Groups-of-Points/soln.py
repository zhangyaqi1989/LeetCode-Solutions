from functools import lru_cache
class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        mins2 = [min(col) for col in zip(*cost)]
        sz1, sz2 = len(cost), len(cost[0])
        @lru_cache(None)
        def dp(idx, mask):
            # need to know who connects with A[idx]
            if idx == sz1:
                return sum(mins2[j] for j in range(sz2) if not (mask & (1 << j)))
            else:
                return min(cost[idx][j] + dp(idx + 1, mask | (1 << j)) for j in range(sz2))
        return dp(0, 0)
