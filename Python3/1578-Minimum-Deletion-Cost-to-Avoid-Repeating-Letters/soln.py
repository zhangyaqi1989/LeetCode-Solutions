class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        # abaac...
        dp = {'' : 0}
        for ch, c in zip(s, cost):
            # delete ch
            new_dp = {key : val + c for key, val in dp.items()}
            new_dp[ch] = min(new_dp.get(ch, math.inf), min(val for key, val in dp.items() if key != ch))
            dp = new_dp
        return min(dp.values())
