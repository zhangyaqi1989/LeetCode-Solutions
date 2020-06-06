class Solution:
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not any(grid): return 0
        m, n = len(grid), len(grid[0])
        def dfs(r, c):
            shape = set()
            stack = [(r, c)]
            grid[r][c] = 0
            while stack:
                i, j = stack.pop()
                shape.add((i - r, j - c))
                for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                    newi, newj = i + di, j + dj
                    if 0 <= newi < m and 0 <= newj < n and grid[newi][newj]:
                        grid[newi][newj] = 0
                        stack.append((newi, newj))
            return frozenset(shape)
        shapes = set()
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val:
                    shape = dfs(i, j)
                    shapes.add(shape)
        return len(shapes)