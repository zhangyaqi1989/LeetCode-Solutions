class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for length in range(2, n + 1):
            for lo in range(n - length + 1):
                hi = lo + length - 1
                if s[lo] == s[hi]:
                    dp[lo][hi] = dp[lo + 1][hi - 1]
                else:
                    dp[lo][hi] = 1 + min(dp[lo + 1][hi], dp[lo][hi - 1])
        return dp[0][n - 1]
