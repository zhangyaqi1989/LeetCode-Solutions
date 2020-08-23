class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        # Pick the most
        piles.sort()
        n = len(piles)
        return sum(piles[n // 3 : n : 2])
