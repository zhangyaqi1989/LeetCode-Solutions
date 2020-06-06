class Solution:
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        elif n == 1:
            return 3
        mod = 10 ** 9 + 7
        dp = [1, 1, 2] # without A
        for i in range(2, n):
            dp.append((dp[-1] + dp[-2] + dp[-3]) % mod)
        ans = (dp[-1] + dp[-2] + dp[-3]) % mod
        for i in range(n):
            ans += dp[i + 1] * dp[n - i] % mod
        return ans % mod
