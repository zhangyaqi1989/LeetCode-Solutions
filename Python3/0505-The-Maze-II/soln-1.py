class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        def neighbor(i, j):
            m, n = len(maze), len(maze[0])
            for di, dj in (-1, 0), (1, 0), (0, -1), (0, 1):
                newi, newj = i + di, j + dj
                cnt = 1
                if not (0 <= newi < m and 0 <= newj < n and maze[newi][newj] == 0):
                    continue
                while 0 <= newi < m and 0 <= newj < n and maze[newi][newj] == 0:
                    newi += di
                    newj += dj
                    cnt += 1
                yield (newi - di, newj - dj), cnt - 1
        pq = [(0, tuple(start))]
        costs = {tuple(start) : 0}
        dst = tuple(destination)
        processed = set()
        while pq:
            cost, node = heapq.heappop(pq)
            if node in processed:
                continue
            if node == dst:
                return cost
            processed.add(node)
            for nei, w in neighbor(*node):
                if nei not in costs or cost + w < costs[nei]:
                    costs[nei] = cost + w
                    heapq.heappush(pq, (cost + w, nei))
        return -1
