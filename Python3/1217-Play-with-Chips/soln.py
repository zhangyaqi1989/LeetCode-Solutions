class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        evens, odds = 0, 0
        for chip in chips:
            if chip % 2:
                odds += 1
            else:
                evens += 1
        return min(odds, evens)
