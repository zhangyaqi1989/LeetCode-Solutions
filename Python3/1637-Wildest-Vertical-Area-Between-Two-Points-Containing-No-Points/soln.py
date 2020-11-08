class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        xs = collections.defaultdict(list)
        for x, y in points:
            xs[x].append(y)
        xs = list(xs.keys())
        xs.sort()
        return max(xs[i + 1] - xs[i] for i in range(len(xs) - 1))
