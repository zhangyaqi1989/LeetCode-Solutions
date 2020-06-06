class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        return sum(val < 0 for row in grid for val in row)
