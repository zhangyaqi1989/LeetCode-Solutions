class Solution:
    def knightProbability(self, N, K, r, c):
        """
        :type N: int
        :type K: int
        :type r: int
        :type c: int
        :rtype: float
        """
        grid = [[0] * N for _ in range(N)]
        grid[r][c] = 1
        for _ in range(K):
            has = False
            temp = [[0] * N for _ in range(N)]
            for i, row in enumerate(grid):
                for j, val in enumerate(row):
                    if val != 0:
                        has = True
                        newval = 0.125 * val
                        for di, dj in (-1, 2), (-1, -2), (-2, 1), (-2, -1), (1, 2), (1, -2), (2, 1), (2, -1):
                            if 0 <= i + di < N and 0 <= j + dj < N:
                                temp[i + di][j + dj] += newval
            if not has:
                return 0
            grid = temp
        return sum(map(sum, grid))
            