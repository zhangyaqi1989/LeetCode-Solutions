class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        N = len(grid)
        seen = [[False] * N for _ in range(N)]
        pq = [(grid[0][0], 0, 0)]
        seen[0][0] = True
        while pq:
            level, i, j = heapq.heappop(pq)
            if i == j == N - 1:
                return level
            for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= ni < N and 0 <= nj < N and not seen[ni][nj]:
                    seen[ni][nj] = True
                    heapq.heappush(pq, (max(level, grid[ni][nj]), ni, nj))
