class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m, n = len(word1), len(word2)
        dp = list(range(n + 1))
        for i in range(1, m + 1):
            temp = dp[:]
            dp[0] = i
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[j] = temp[j - 1]
                else:
                    dp[j] = min(temp[j], dp[j - 1], temp[j - 1]) + 1
        return dp[-1]