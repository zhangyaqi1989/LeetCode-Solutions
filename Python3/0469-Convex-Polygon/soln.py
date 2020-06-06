class Solution:
    def isConvex(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        def ccw(a, b, c):
            return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
        d = None
        for i in range(len(points)):
            cur_d = ccw(points[i - 2], points[i - 1], points[i])
            if cur_d == 0:
                continue
            if d is None:
                d = cur_d
            else:
                if d * cur_d < 0:
                    return False
        return True
