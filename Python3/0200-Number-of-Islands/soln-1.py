class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0
        m, n = len(grid), len(grid[0])
        def neighbor(r, c):
            for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                newr, newc = r + dr, c + dc
                if 0 <= newr < m and 0 <= newc < n:
                    yield newr, newc
        def dfs(r, c):
            grid[r][c] = '0'
            stack = [(r, c)]
            while stack:
                i, j = stack.pop()
                for newi, newj in neighbor(i, j):
                    if grid[newi][newj] == '1':
                        grid[newi][newj] = '0'
                        stack.append((newi, newj))
        cnt = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == '1':
                    dfs(i, j)
                    cnt += 1
        return cnt