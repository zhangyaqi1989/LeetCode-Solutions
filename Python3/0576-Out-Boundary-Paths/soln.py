import numpy as np
class Solution(object):
    def findPaths(self, m, n, N, i, j):
        """
        :type m: int
        :type n: int
        :type N: int
        :type i: int
        :type j: int
        :rtype: int
        """
        grid = np.zeros((m, n), dtype=np.int64)
        grid[i][j] = 1
        out = 0
        mod = 10**9 + 7
        for _ in range(N):
            prev = grid % mod
            grid = np.zeros((m, n), dtype=np.int64)
            grid[1:] += prev[:-1]
            grid[:-1] += prev[1:]
            grid[:, 1:] += prev[:, :-1]
            grid[:, :-1] += prev[:, 1:]
            out += 4 * prev.sum() - grid.sum()
        return int(out % mod)
