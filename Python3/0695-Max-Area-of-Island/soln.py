class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        def neighbors(r, c):
            for dr, dc in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                if 0 <= r + dr < m and 0 <= c + dc < n:
                    yield (r + dr, c + dc)
        def dfs(r, c):
            stack = [(r, c)]
            grid[r][c] = 0
            area = 0
            while stack:
                i, j = stack.pop()
                area += 1
                for newi, newj in neighbors(i, j):
                    if grid[newi][newj]:
                        grid[newi][newj] = 0
                        stack.append((newi, newj))
            return area
        max_area = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    area = dfs(i, j)
                    if area > max_area:
                        max_area = area
        return max_area