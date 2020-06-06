class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        col, row = n, m
        for j in range(n):
            if obstacleGrid[0][j] == 1:
                col = j
                break
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                row = i
                break
        for j in range(n):
            obstacleGrid[0][j] = int(j < col)
        for i in range(m):
            obstacleGrid[i][0] = int(i < row)
        for i in range(1, m):
            for j in range(1, n):
                obstacleGrid[i][j] = 0 if obstacleGrid[i][j] == 1 else obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1]
        return obstacleGrid[-1][-1]