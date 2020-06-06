class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        src = tuple(start)
        target = tuple(destination)
        processed = set()
        frontier = [(0, src)]
        m, n = len(maze), len(maze[0])
        while frontier:
            c, (i, j) = heapq.heappop(frontier)
            if (i, j) == target:
                return c
            if (i, j) in processed:
                continue
            processed.add((i, j))
            for di, dj in (0, 1), (0, -1), (1, 0), (-1, 0):
                ni, nj = i + di, j + dj
                cnt = 1
                while 0 <= ni < m and 0 <= nj < n and maze[ni][nj] == 0:
                    ni += di
                    nj += dj
                    cnt += 1
                ni -= di
                nj -= dj
                cnt -= 1
                if cnt > 0:
                    heapq.heappush(frontier, (c + cnt, (ni, nj)))
        return -1
