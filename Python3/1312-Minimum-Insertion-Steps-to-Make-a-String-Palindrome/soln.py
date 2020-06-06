class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for length in range(2, n + 1):
            for lo in range(n - length + 1):
                # lo : lo + length
                if s[lo] == s[lo + length - 1]:
                    dp[lo][lo + length - 1] = dp[lo + 1][lo + length - 2]
                else:
                    dp[lo][lo + length - 1] = 1 + min(dp[lo + 1][lo + length - 1], dp[lo][lo + length - 2])
        return dp[0][n - 1]
