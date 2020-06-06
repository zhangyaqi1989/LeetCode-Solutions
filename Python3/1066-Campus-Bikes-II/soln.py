from functools import lru_cache
class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        @lru_cache(None)
        def dfs(mask, idx):
            if idx == len(workers):
                return 0
            ans = math.inf
            for i in range(len(bikes)):
                if (mask & (1 << i)) == 0:
                    new_mask = mask | (1 << i)
                    ans = min(ans, abs(workers[idx][0] - bikes[i][0]) + abs(workers[idx][1] - bikes[i][1]) + dfs(new_mask, idx + 1))
            return ans
        return dfs(0, 0)
