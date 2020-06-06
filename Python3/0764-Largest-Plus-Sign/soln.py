class Solution:
    def orderOfLargestPlusSign(self, N, mines):
        """
        :type N: int
        :type mines: List[List[int]]
        :rtype: int
        """
        grid = [[min(i, j, N - 1 - i, N - 1 - j) + 1 for j in range(N)] 
                 for i in range(N)]
        for x, y in mines:
            for i in range(N):
                grid[i][y] = min(grid[i][y], abs(i - x))
                grid[x][i] = min(grid[x][i], abs(i - y))
        return max(map(max, grid))
