class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        ns, np = len(s), len(p)
        dp = [[False] * (np + 1) for _ in range(ns + 1)]
        dp[0][0] = True
        for j in range(2, np + 1, 2):
            if p[j - 1] == '*' and dp[0][j - 2]:
                dp[0][j] = True
        for i in range(1, ns + 1):
            for j in range(1, np + 1):
                if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2]
                    if p[j - 2] == '.' or p[j - 2] == s[i - 1]:
                        dp[i][j] = dp[i][j - 2] or dp[i - 1][j - 2] or dp[i - 1][j]
        return dp[-1][-1]
