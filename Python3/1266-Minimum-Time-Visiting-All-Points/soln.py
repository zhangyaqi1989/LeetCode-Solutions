class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        def compute_time(p1, p2):
            x1, y1 = p1
            x2, y2 = p2
            dx, dy = abs(x1 - x2), abs(y1 - y2)
            return dx + dy - min(dx, dy)
        n = len(points)
        return sum(compute_time(points[i], points[i - 1]) for i in range(1, n))
