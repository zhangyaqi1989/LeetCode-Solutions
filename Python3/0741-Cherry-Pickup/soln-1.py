from functools import lru_cache
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        N = len(grid)
        @lru_cache(None)
        def helper(r1, c1, r2):
            c2 = (r1 + c1) - r2
            if r1 == N or c1 == N or c2 == N or r2 == N or grid[r1][c1] == -1 or grid[r2][c2] == -1:
                return -math.inf
            elif r1 == c1 == N - 1:
                return grid[r1][c1]
            else:
                ans = grid[r1][c1] + (r1 != r2) * grid[r2][c2]
                ans += max(helper(r1 + 1, c1, r2), helper(r1, c1 + 1, r2), helper(r1 + 1, c1, r2 + 1), helper(r1, c1 + 1, r2 + 1))
            return ans
        ans = helper(0, 0, 0)
        return ans if ans != -math.inf else 0
