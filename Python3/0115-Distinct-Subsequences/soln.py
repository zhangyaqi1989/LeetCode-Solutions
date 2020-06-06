class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        # count how many distinct subsequence of s equals to t
        # define dp[i][j] to be s[:j] t[:i]
        m, n = len(t), len(s)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for j in range(n + 1):
            dp[0][j] = 1
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if t[i - 1] == s[j - 1]:
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        return dp[-1][-1]