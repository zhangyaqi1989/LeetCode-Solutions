class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        return sum(val > 0 for row in grid for val in row) + sum(max(row) for row in grid) + sum(max(col) for col in zip(*grid))