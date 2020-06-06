class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                dp[i + 1][j + 1] = mat[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j]
        ans = [[0] * n for _ in range(m)]
        for r in range(m):
            for c in range(n):
                r0 = max(0, r - K)
                c0 = max(0, c - K)
                r1 = min(m - 1, r + K)
                c1 = min(n - 1, c + K)
                ans[r][c] = dp[r1 + 1][c1 + 1] + dp[r0][c0] - dp[r1 + 1][c0] - dp[r0][c1 + 1]
        return ans
