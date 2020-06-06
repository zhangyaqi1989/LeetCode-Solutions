class Solution:
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap or not heightMap[0]:
            return 0
        heap = []
        m, n = len(heightMap), len(heightMap[0])
        seen = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0 or i == m - 1 or j == n - 1:
                    heapq.heappush(heap, (heightMap[i][j], i, j))
                    seen[i][j] = 1
        ans = 0
        while heap:
            height, i, j = heapq.heappop(heap)
            for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                newi, newj = i + di, j + dj
                if 0 <= newi < m and 0 <= newj < n and seen[newi][newj] == 0:
                    seen[newi][newj] = 1
                    ans += max(0, height - heightMap[newi][newj])
                    heapq.heappush(heap, (max(heightMap[newi][newj], height), newi, newj))
        return ans
            