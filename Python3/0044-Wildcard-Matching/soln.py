class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # dp[i][j] is whether s[:j] matches p[:i]
        # p is pattern
        ns, np = len(s), len(p)
        dp = [[False] * (ns + 1) for _ in range(np + 1)]
        dp[0][0] = True
        # first row: i == 0, p[:i] is empty, False except j == 0
        # first column, j == 0, s[:j] is empty
        for i in range(1, np + 1):
            if p[i - 1] == '*':
                dp[i][0] = True
            else:
                break
        for i in range(1, np + 1):
            for j in range(1, ns + 1):
                if p[i - 1] == s[j - 1] or p[i - 1] == '?':
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    if p[i - 1] == '*':
                        # discuss by case
                        # empty sequence, length one, and many
                        if dp[i - 1][j] or dp[i - 1][j - 1] or dp[i][j - 1]:
                            dp[i][j] = True
        return dp[-1][-1]
