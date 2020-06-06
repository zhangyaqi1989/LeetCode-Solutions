class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        if not any(grid):
            return 0
        side = sum(map(max, grid))
        front = sum(map(max, zip(*grid)))
        top = sum(val != 0 for row in grid for val in row)
        return top + front + side 
