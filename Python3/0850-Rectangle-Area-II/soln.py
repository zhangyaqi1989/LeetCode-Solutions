class Solution:
    def rectangleArea(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        xs = [x for x1, _, x2, _ in rectangles for x in (x1, x2)]
        ys = [y for _, y1, _, y2 in rectangles for y in (y1, y2)]
        xs = sorted(set(xs))
        ys = sorted(set(ys))
        m = [[0] * len(ys) for _ in range(len(xs))]
        res = 0
        for x1, y1, x2, y2 in rectangles:
            x_idx = bisect.bisect_left(xs, x1)
            j_idx = bisect.bisect_left(ys, y1)
            i = x_idx
            while xs[i] < x2:
                j = j_idx
                while ys[j] < y2:
                    if m[i][j] == 0:
                        m[i][j] += 1
                        res += (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j])
                    j += 1
                i += 1
        return res % (10**9 + 7)