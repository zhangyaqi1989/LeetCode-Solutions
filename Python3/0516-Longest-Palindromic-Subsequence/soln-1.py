class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # common subsequence of s and s[::-1]
        t = s[::-1]
        n = len(s)
        if t == s:
            return n
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
