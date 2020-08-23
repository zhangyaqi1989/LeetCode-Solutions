class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if grid[i][j] != '#':
                    frontier = [(i, j)]
                    while frontier:
                        nxt_level = []
                        for i, j in frontier:
                            if grid[i][j] == '#':
                                return True
                            for ni, nj in (i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1):
                                if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] == grid[i][j]:
                                    nxt_level.append((ni, nj))
                            grid[i][j] = '#'
                        frontier = nxt_level
        return False
