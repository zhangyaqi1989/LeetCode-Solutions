class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # at most two transactions
        # four states, hold1, hold2, free1, free2
        hold1 = -math.inf
        free1 = 0
        hold2 = -math.inf
        free2 = -math.inf
        for p in prices:
            hold1 = max(hold1, -p)
            hold2 = max(hold2, free1 - p)
            free1 = max(free1, hold1 + p)
            free2 = max(free2, hold2 + p)
        return max(free1, free2)
