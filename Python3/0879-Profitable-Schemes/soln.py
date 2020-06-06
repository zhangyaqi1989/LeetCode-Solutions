class Solution:
    def profitableSchemes(self, G, P, group, profit):
        """
        :type G: int
        :type P: int
        :type group: List[int]
        :type profit: List[int]
        :rtype: int
        """
        # dp[i][j] i profile, j members
        mod = 10 ** 9 + 7
        dp = [[0] * (G + 1) for _ in range(P + 1)]
        dp[0][0] = 1
        for p, g in zip(profit, group):
            for i in range(P + 1):
                for j in range(G - g + 1):
                    dp[min(i + p, P)][j + g] += dp[i][j]
        # print(dp)
        return sum(dp[P]) % mod
