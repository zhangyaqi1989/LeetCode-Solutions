class Solution:
    def numOfArrays(self, N: int, M: int, K: int) -> int:
        dp = [[[0] * (M + 1) for _ in range(K + 1)] for _ in range(N + 1)]
        MOD = 1000000007
        for mx in range(1, M + 1):
            dp[1][1][mx] = 1
        for i in range(2, N + 1):
            for k in range(1, K + 1):
                pres = [0]
                for mx in range(1, M + 1):
                    pres.append(pres[-1] + dp[i - 1][k - 1][mx])
                for mx in range(1, M + 1):
                    dp[i][k][mx] = (dp[i][k][mx] + mx * dp[i - 1][k][mx]) % MOD
                    # sum over dp[i - 1][k - 1][1...mx - 1]
                    dp[i][k][mx] = (dp[i][k][mx] + pres[mx - 1]) % MOD
        return sum(dp[N][K][mx] for mx in range(1, M + 1)) % MOD
