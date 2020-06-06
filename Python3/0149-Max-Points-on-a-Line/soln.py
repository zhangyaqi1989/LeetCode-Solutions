# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        n = len(points)
        ans = 0
        for i, point in enumerate(points):
            ax, ay = point.x, point.y
            d = {float('inf') : 1}
            dup = 0
            for j in range(n):
                if j == i:
                    continue
                bx, by = points[j].x, points[j].y
                if ax == bx and ay == by:
                    dup += 1
                else:
                    if ax == bx:
                        slope = float('inf')
                    else:
                        dy, dx = by - ay, bx - ax
                        div = math.gcd(dy, dx)
                        slope = (dx / div, dy / div)
                    d[slope] = d.get(slope, 1) + 1
            ans = max(ans, max(d.values()) + dup)
        return ans