class Solution:
    def minWindow(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        m, n = len(T), len(S)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for j in range(n + 1):
            dp[0][j] = j + 1
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if S[j - 1] == T[i - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        start = 0
        l = n + 1
        for j in range(1, n + 1):
            if dp[m][j] != 0:
                if j - dp[m][j] + 1 < l:
                    start = dp[m][j] - 1
                    l = j - dp[m][j] + 1
        return "" if l == n + 1 else S[start:start + l]