class Solution:
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not any(heightMap):
            return 0
        heap = []
        m, n = len(heightMap), len(heightMap[0])
        seen = [[False] * n for _ in range(m)]
        for i, row in enumerate(heightMap):
            for j, height in enumerate(row):
                if i == 0 or j == 0 or i == m - 1 or j == n - 1:
                    seen[i][j] = True
                    heapq.heappush(heap, (height, i, j))
        ans = 0
        while heap:
            height, i, j = heapq.heappop(heap)
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n and not seen[newi][newj]:
                    seen[newi][newj] = True
                    ans += max(0, height - heightMap[newi][newj])
                    heapq.heappush(heap, (max(heightMap[newi][newj], height), newi, newj))
        return ans
