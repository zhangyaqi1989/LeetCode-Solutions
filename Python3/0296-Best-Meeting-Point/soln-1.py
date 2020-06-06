import statistics
class Solution:
    def minTotalDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        xs, ys = [], []
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    xs.append(i)
                    ys.append(j)
        def helper(array):
            median = int(statistics.median(array))
            return sum(abs(x - median) for x in array)
        return helper(xs) + helper(ys)
