class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # suffix
        # DP[i, j] is the minimum distance of word1[i:] and word2[j:]
        n1, n2 = len(word1), len(word2)
        dp = [[math.inf] * (n2 + 1) for _ in range(n1 + 1)]
        dp[n1][n2] = 0
        for j in range(n2):
            dp[n1][j] = n2 - j
        for i in range(n1):
            dp[i][n2] = n1 - i
        for i in reversed(range(n1)):
            for j in reversed(range(n2)):
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]) + 1
        return dp[0][0]
