class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [math.inf] * (amount + 1)
        dp[0] = 0
        for num in range(1, amount + 1):
            for coin in coins:
                if num >= coin:
                    dp[num] = min(dp[num], dp[num - coin] + 1)
        return dp[-1] if dp[-1] != math.inf else -1
        
