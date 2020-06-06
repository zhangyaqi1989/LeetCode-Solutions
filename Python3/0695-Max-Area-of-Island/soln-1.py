class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0
        def dfs(r, c):
            m, n = len(grid), len(grid[0])
            stack = [(r, c)]
            grid[r][c] = 0
            ans = 0
            while stack:
                i, j = stack.pop()
                ans += 1
                for di, dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                    newi, newj = i + di, j + dj
                    if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == 1:
                        grid[newi][newj] = 0
                        stack.append((newi, newj))
            return ans
        ans = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    area = dfs(i, j)
                    if area > ans:
                        ans = area
        return ans
