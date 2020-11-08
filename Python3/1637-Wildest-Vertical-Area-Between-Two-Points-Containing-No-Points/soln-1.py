class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        xs = set([x for x, _ in points])
        xs = sorted(list(xs))
        return max(xs[i + 1] - xs[i] for i in range(len(xs) - 1))
