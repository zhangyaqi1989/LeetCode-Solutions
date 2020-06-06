class Solution:
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        # this is a typical DP
        m, n = len(s1) + 1, len(s2) + 1
        dp = [[0] * n for _ in range(m)]
        for i in range(1, m):
            dp[i][0] = dp[i - 1][0] + ord(s1[i - 1])
        for j in range(1, n):
            dp[0][j] = dp[0][j - 1] + ord(s2[j - 1])
        for i in range(1, m):
            for j in range(1, n):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j] + ord(s1[i - 1]), dp[i][j - 1] + ord(s2[j - 1]), dp[i - 1][j - 1] + ord(s1[i - 1]) + ord(s2[j - 1]))
        return dp[-1][-1]