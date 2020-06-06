class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return -1
        m, n = len(grid), len(grid[0])
        seen = {(0, 0)}
        frontier = collections.deque([(0, 0)])
        step = 1
        while frontier:
            sz = len(frontier)
            for _ in range(sz):
                i, j = frontier.popleft()
                if i == m - 1 and j == n - 1:
                    return step
                for di in (-1, 0, 1):
                    for dj in (-1, 0, 1):
                        if di == dj == 0:
                            continue
                        ni, nj = i + di, j + dj
                        if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] == 0 and (ni, nj) not in seen:
                            seen.add((ni, nj))
                            frontier.append((ni, nj))
            step += 1
        return -1
