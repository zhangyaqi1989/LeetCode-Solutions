from pprint import pprint
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        # DP[i, j] is the num of distinct subsequence of s[i:] and t[j:]
        ns, nt = len(s), len(t)
        dp = [[0] * (nt + 1) for _ in range(ns + 1)]
        for i in range(ns + 1):
            dp[i][nt] = 1
        for i in reversed(range(ns)):
            for j in reversed(range(nt)):
                if s[i] == t[j]:
                    dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1]
                else:
                    dp[i][j] = dp[i + 1][j]
        return dp[0][0]
