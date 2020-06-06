class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        # match person to hat
        n = len(hats)
        dp = [0] * (1 << n)
        dp[0] = 1
        MOD = 1000000007
        # need to know which people is perfer i-th hat
        peoples = [[] for i in range(41)]
        for i, hs in enumerate(hats):
            for h in hs:
                peoples[h].append(i)
        for h in range(1, 41):
            new_dp = dp[:]
            for state in range(1 << n):
                for p in peoples[h]:
                    if (state & (1 << p)) == 0:
                        new_state = state | (1 << p)
                        new_dp[new_state] = (new_dp[new_state] + dp[state]) % MOD
            dp = new_dp
        return dp[(1 << n) - 1]
