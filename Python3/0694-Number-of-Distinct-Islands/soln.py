class Solution(object):
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        def neighbors(r, c):
            for dr, dc in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                if 0 <= r + dr < m and 0 <= c + dc < n:
                    yield r + dr, c + dc
        def dfs(r, c):
            stack = [(r, c)]
            island = {(0, 0)}
            while stack:
                i, j = stack.pop()
                for newi, newj in neighbors(i, j):
                    if grid[newi][newj] == 1:
                        grid[newi][newj] = 0
                        stack.append((newi, newj))
                        island.add((newi - r, newj - c))
            return frozenset(island)
        islands = set()
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    islands.add(dfs(i, j))
        return len(islands)