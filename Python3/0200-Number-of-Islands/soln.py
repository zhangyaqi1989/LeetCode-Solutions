class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def dfs(r, c):
            m, n = len(grid), len(grid[0])
            stack = [(r, c)]
            grid[r][c] = '0'
            while stack:
                i, j = stack.pop()
                for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                    newi, newj = i + di, j + dj
                    if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == '1':
                        stack.append((newi, newj))
                        grid[newi][newj] = '0'
        cnt = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == '1':
                    dfs(i, j)
                    cnt += 1
        return cnt