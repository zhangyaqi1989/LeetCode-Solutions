class Solution:
    def orangesRotting(self, grid: 'List[List[int]]') -> 'int':
        queue = collections.deque()
        cnt = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 2:
                    queue.append((i, j))
                if val == 1:
                    cnt += 1
        if cnt == 0:
            return 0
        steps = 0
        m, n = len(grid), len(grid[0])
        while queue:
            size = len(queue)
            if cnt == 0:
                return steps
            steps += 1
            for _ in range(size):
                i, j = queue.popleft()
                for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == 1:
                        grid[newi][newj] = 2
                        cnt -= 1
                        queue.append((newi, newj))
        return steps if cnt == 0 else -1
