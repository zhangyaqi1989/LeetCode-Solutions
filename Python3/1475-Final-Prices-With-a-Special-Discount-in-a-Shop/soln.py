class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        ans = prices[:]
        stack = []
        for i, p in enumerate(prices):
            while stack and p <= prices[stack[-1]]:
                ans[stack.pop()] -= p
            stack.append(i)
        return ans
