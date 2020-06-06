class Solution:
    def shortestDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not any(grid):
            return 0
        m, n = len(grid), len(grid[0])
        hits, distances = [[0] * n for _ in range(m)], [[0] * n for _ in range(m)]
        buildings = sum(grid[i][j] == 1 for i in range(m) for j in range(n))
        def dfs(r, c, buildings):
            count = 1
            m, n = len(grid), len(grid[0])
            visited = [[False] * n for _ in range(m)]
            visited[r][c] = True
            queue = collections.deque([(r, c, 0)])
            while queue:
                i, j, dis = queue.popleft()
                for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= newi < m and 0 <= newj < n and not visited[newi][newj]:
                        visited[newi][newj] = True
                        if not grid[newi][newj]:
                            hits[newi][newj] += 1
                            distances[newi][newj] += dis + 1
                            queue.append((newi, newj, dis + 1))
                        elif grid[newi][newj] == 1:
                            count += 1
            return count == buildings
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    if not dfs(i, j, buildings):
                        return -1
        ans = min([distances[i][j] for i in range(m) for j in range(n) if hits[i][j] == buildings] or [0])
        return -1 if not ans else ans