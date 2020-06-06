class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        mx = days[-1]
        dp = [math.inf] * (mx + 1)
        dp[0] = 0
        i = 0
        c1, c7, c30 = costs
        for day in range(1, mx + 1):
            if days[i] != day:
                dp[day] = dp[day - 1]
            else:
                i += 1
                dp[day] = min(c1 + dp[day - 1], c7 + dp[max(0, day - 7)], c30 + dp[max(0, day - 30)])
        return dp[-1]
