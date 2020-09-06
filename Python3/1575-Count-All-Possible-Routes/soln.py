class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        dp = [[-1] * 201 for _ in range(101)]
        dp[start][fuel] = 1
        MOD = 1000000007
        def helper(pos, left):
            if dp[pos][left] != -1:
                return dp[pos][left]
            ans = 0
            for i, loc in enumerate(locations):
                if i != pos and abs(loc - locations[pos]) + left <= fuel:
                    ans += helper(i, left + abs(loc - locations[pos]))
            ans %= MOD
            dp[pos][left] = ans
            return ans
        return sum(helper(finish, left) for left in range(fuel + 1)) % MOD
