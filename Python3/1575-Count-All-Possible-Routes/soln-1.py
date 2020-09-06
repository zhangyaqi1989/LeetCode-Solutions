class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        dp = [[-1] * 201 for _ in range(101)]
        MOD = 1000000007
        def helper(pos, left):
            if left < 0:
                return 0
            if dp[pos][left] != -1:
                return dp[pos][left]
            ans = 1 if pos == finish else 0
            for i, loc in enumerate(locations):
                if i != pos and left - abs(loc - locations[pos]) >= 0:
                    ans += helper(i, left - abs(loc - locations[pos]))
            ans %= MOD
            dp[pos][left] = ans
            return ans
        return helper(start, fuel)
