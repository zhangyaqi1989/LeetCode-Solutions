class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        na, nb = len(A), len(B)
        dp = [[0] * (nb + 1) for _ in range(na + 1)]
        for i in range(1, na + 1):
            for j in range(1, nb + 1):
                if A[i - 1] == B[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[na][nb]
