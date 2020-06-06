class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not any(heightMap):
            return 0
        m, n = len(heightMap), len(heightMap[0])
        pq = []
        visited = set()
        for j in range(n):
            pq.append((heightMap[0][j], 0, j))
            pq.append((heightMap[m - 1][j], m - 1, j))
            visited.add((0, j))
            visited.add((m - 1, j))
        for i in range(1, m - 1):
            pq.append((heightMap[i][0], i, 0))
            pq.append((heightMap[i][n - 1], i, n - 1))
            visited.add((i, 0))
            visited.add((i, n - 1))
        heapq.heapify(pq)
        water = 0
        while pq:
            level, i, j = heapq.heappop(pq)
            for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= ni < m and 0 <= nj < n and (ni, nj) not in visited:
                    visited.add((ni, nj))
                    water += max(level - heightMap[ni][nj], 0)
                    heapq.heappush(pq, (max(level, heightMap[ni][nj]), ni, nj))
        return water
