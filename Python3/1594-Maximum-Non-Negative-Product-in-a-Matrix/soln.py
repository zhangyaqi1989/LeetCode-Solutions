class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        # maximum non-negative product
        # maximum, negative
        h, w = len(grid), len(grid[0])
        dp = [[[None, None] for _ in range(w)] for _ in range(h)]
        dp[0][0] = [grid[0][0], grid[0][0]]
        for c in range(1, w):
            dp[0][c][0] = max(dp[0][c - 1][0] * grid[0][c], dp[0][c - 1][1] * grid[0][c])
            dp[0][c][1] = min(dp[0][c - 1][0] * grid[0][c], dp[0][c - 1][1] * grid[0][c])
        for r in range(1, h):
            dp[r][0][0] = max(dp[r - 1][0][0] * grid[r][0], dp[r - 1][0][1] * grid[r][0])
            dp[r][0][1] = min(dp[r - 1][0][0] * grid[r][0], dp[r - 1][0][1] * grid[r][0])
        for r in range(1, h):
            for c in range(1, w):
                val = grid[r][c]
                dp[r][c][0] = max(dp[r - 1][c][0] * val, dp[r - 1][c][1] * val, dp[r][c - 1][0] * val, dp[r][c - 1][1] * val)
                dp[r][c][1] = min(dp[r - 1][c][0] * val, dp[r - 1][c][1] * val, dp[r][c - 1][0] * val, dp[r][c - 1][1] * val)
        if dp[-1][-1][0] < 0 and dp[-1][-1][1] < 0:
            return -1
        else:
            return max(dp[-1][-1][0], dp[-1][-1][1]) % 1000000007
