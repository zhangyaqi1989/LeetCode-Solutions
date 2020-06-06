class Solution:
    def shortestDistance(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: int
        """
        m, n = len(maze), len(maze[0])
        start, dest = tuple(start), tuple(destination)
        heap = []
        heapq.heappush(heap, [0, start])
        visited = {start : 0}
        while heap:
            dis, (i, j), = heapq.heappop(heap)
            if (i, j) == dest:
                return dis
            for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                newi, newj = i + di, j + dj
                while 0 <= newi < m and 0 <= newj < n and maze[newi][newj] != 1:
                    newi, newj = newi + di, newj + dj
                newi, newj = newi - di, newj - dj
                if newi != i or newj != j:
                    distance = dis + ((newi - i) // di if newi != i else (newj - j) // dj)
                else:
                    distance = dis
                if (newi, newj) not in visited or visited[newi, newj] > distance:
                    visited[newi, newj] = distance
                    heapq.heappush(heap, (distance, (newi, newj)))
        return -1