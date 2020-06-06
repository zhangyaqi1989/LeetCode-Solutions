class Solution:
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        x_to_ys = collections.defaultdict(set)
        for x, y in points:
            x_to_ys[x].add(y)
        mn_area = math.inf
        for x1, y1 in points:
            for x2, y2 in points:
                if x1 == x2 or y1 == y2:
                    continue
                if y2 in x_to_ys[x1] and y1 in x_to_ys[x2]:
                    mn_area = min(mn_area, abs(x2 - x1) * abs(y2 - y1))
        return mn_area if mn_area != math.inf else 0
