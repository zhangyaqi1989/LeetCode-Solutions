from functools import lru_cache
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        h, w = len(grid), len(grid[0])
        @lru_cache(None)
        def dp(r, c1, c2):
            if r == h - 1:
                return grid[r][c1] if c1 == c2 else grid[r][c1] + grid[r][c2]
            ans = -math.inf
            for next_c1 in (c1 - 1, c1, c1 + 1):
                if 0 <= next_c1 < w:
                    for next_c2 in (c2 - 1, c2, c2 + 1):
                        if 0 <= next_c2 < w:
                            ans = max(ans, dp(r + 1, next_c1, next_c2))
            return ans + (grid[r][c1] if c1 == c2 else grid[r][c1] + grid[r][c2])
        return dp(0, 0, w - 1)
