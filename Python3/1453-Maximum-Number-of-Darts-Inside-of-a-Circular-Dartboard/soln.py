class Solution:
    def numPoints(self, points: List[List[int]], r: int) -> int:
        # maximum number
        # How many points encluded
        # number of points
        if len(points) == 1:
            return 1
        n = len(points)
        r2 = r * r
        ans = 1
        TOL = 0.000000001
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                if x1 == x2 and y1 == y2:
                    continue
                dx, dy = x2 - x1, y2 - y1
                xmid, ymid = 0.5 * (x1 + x2), 0.5 * (y1 + y2)
                d = math.hypot(dx, dy)
                try:
                    l = math.sqrt(r2 - 0.25 * dx * dx - 0.25 * dy * dy)
                    for dxx, dyy in [(dy, -dx), (-dy, dx)]:
                        # d = math.sqrt(dxx * dxx + dyy ** dyy)
                        unitx = dxx / d
                        unity = dyy / d
                        xc, yc = xmid + unitx * l, ymid + unity * l
                        cnt = sum(math.hypot(x - xc, y - yc) <= r + TOL for x, y in points)
                        ans = max(ans, cnt)
                except:
                    pass
        return ans
