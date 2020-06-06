class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        ns, nt = len(s), len(t)
        dp = [[0] * (ns + 1) for _ in range(nt + 1)]
        for j in range(ns + 1):
            dp[0][j] = 1
        for i in range(1, nt + 1):
            for j in range(1, ns + 1):
                if s[j - 1] == t[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        return dp[-1][-1]
