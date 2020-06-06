class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        # 1 to n
        # exact k inverse
        # f(n, k) = f(n - 1, j) i in [max(k - (n - 1), 0), k]
        # f(0, k) = 0
        # f(n, 0) = 1
        dp = [1] + [0] * k
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                dp[j] += dp[j - 1]
            for j in range(k, -1, -1):
                if j - (i - 1) > 0:
                    dp[j] -= dp[j - (i - 1) - 1]
        mod = 1000000007
        return dp[-1] % mod
