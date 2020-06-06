class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        sorted_heights = sorted(heights)
        return sum(a != b for a, b in zip(sorted_heights, heights))
