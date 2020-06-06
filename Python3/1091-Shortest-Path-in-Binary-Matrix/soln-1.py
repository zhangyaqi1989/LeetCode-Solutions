class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1:
            return -1
        def neighbor8(i, j):
            n = len(grid)
            for di in (-1, 0, 1):
                for dj in (-1, 0, 1):
                    if di == dj == 0:
                        continue
                    newi, newj = i + di, j + dj
                    if 0 <= newi < n and 0 <= newj < n and grid[newi][newj] == 0:
                        yield (newi, newj)
        n = len(grid)
        ds = [[math.inf] * n for _ in range(n)]
        queue = collections.deque([(0, 0)])
        ds[0][0] = 1
        while queue:
            i, j = queue.popleft()
            if i == j == n - 1:
                return ds[n - 1][n - 1]
            for newi, newj in neighbor8(i, j):
                if ds[i][j] + 1 < ds[newi][newj]:
                    ds[newi][newj] = ds[i][j] + 1
                    queue.append((newi, newj))
        return -1
