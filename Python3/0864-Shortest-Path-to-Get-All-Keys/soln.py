class Solution:
    def shortestPathAllKeys(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        K = -1
        x, y = -1, -1
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == '@':
                    x, y = i, j # record the start point
                if val in 'abcdef':
                    K = max(K, ord(val) - ord('a') + 1)
        target = (1 << K) - 1
        start = (0, x, y)
        queue = collections.deque([start])
        visited = {start}
        step = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                state, i, j = queue.popleft()
                if state == target:
                    return step
                for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] != '#':
                        if grid[newi][newj] in 'ABCDEF' and state & (1 << (ord(grid[newi][newj]) - ord('A'))) == 0:
                            continue
                        if grid[newi][newj] in 'abcdef':
                            new_state = state | (1 << (ord(grid[newi][newj]) - ord('a')))
                        else:
                            new_state = state
                        if (new_state, newi, newj) not in visited:
                            visited.add((new_state, newi, newj))
                            queue.append((new_state, newi, newj))
            step += 1
        return -1
