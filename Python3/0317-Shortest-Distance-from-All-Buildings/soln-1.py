class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        if not any(grid):
            return 0
        m, n = len(grid), len(grid[0])
        nbuilds = 0
        dist = [[0] * n for _ in range(m)]
        reach = [[0] * n for _ in range(m)]
        def bfs(i0, j0):
            frontier = collections.deque([(0, i0, j0)])
            visited = [[False] * n for _ in range(m)]
            visited[i0][j0] = True
            while frontier:
                cost, i, j = frontier.popleft()
                for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] == 0 and not visited[ni][nj]:
                        visited[ni][nj] = True
                        dist[ni][nj] += cost + 1
                        reach[ni][nj] += 1
                        frontier.append((cost + 1, ni, nj))
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    bfs(i, j)
                    nbuilds += 1
        mn = math.inf
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 0 and reach[i][j] == nbuilds and dist[i][j] < mn:
                    mn = dist[i][j]
        return mn if mn != math.inf else -1
