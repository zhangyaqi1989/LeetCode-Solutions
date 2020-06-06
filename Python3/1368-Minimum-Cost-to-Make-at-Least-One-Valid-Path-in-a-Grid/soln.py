class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = {1 : (0, 1), 2 : (0, -1), 3 : (1, 0), 4 : (-1, 0)}
        frontier = [(0, 0, 0)]
        processed = [[False] * n for _ in range(m)]
        costs = [[math.inf] * n for _ in range(m)]
        costs[0][0] = 0
        while frontier:
            cost, r, c = heapq.heappop(frontier)
            if r == m - 1 and c == n - 1:
                return costs[r][c]
            if processed[r][c]:
                continue
            processed[r][c] = True
            di, dj = dirs[grid[r][c]]
            for dr, dc in (-1, 0), (1, 0), (0, -1), (0, 1):
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n:
                    weight = 0 if (di == dr and dj == dc) else 1
                    if costs[nr][nc] > cost + weight:
                        costs[nr][nc] = cost + weight
                        heapq.heappush(frontier, (cost + weight, nr, nc))
        return -1
