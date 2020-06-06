import statistics
class Solution:
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        def valid(vals, median):
            return all(2 * median - val in vals for val in vals if val < median)
        xs = collections.defaultdict(set)
        for x, y in points:
            xs[y].add(x)
        medians = [statistics.median(vals) for vals in xs.values()]
        return len(set(medians)) <= 1 and all(valid(vals, median) for vals, median in zip(xs.values(), medians))
