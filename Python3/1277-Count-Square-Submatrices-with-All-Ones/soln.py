class Solution:
    def countSquares(self, mat: List[List[int]]) -> int:
        h, w = len(mat), len(mat[0])
        dp = [[0] * (w + 1) for _ in range(h + 1)]
        ans = 0
        for i, row in enumerate(mat):
            for j, val in enumerate(row):
                if val == 1:
                    dp[i + 1][j + 1] = 1 + min(dp[i][j], dp[i + 1][j], dp[i][j + 1])
                    ans += dp[i + 1][j + 1]
        return ans
