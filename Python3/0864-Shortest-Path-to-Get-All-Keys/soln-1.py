class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        frontier = []
        seen = set()
        cnt = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == '@':
                    frontier.append((i, j, 0))
                    seen.add((i, j, 0))
                elif val in 'abcdefABCDEF':
                    cnt += 1
        locks = "ABCDEF"
        keys = "abcdef"
        cnt //= 2
        locks = locks[:cnt]
        keys = keys[:cnt]
        steps = 0
        target = (1 << cnt) - 1
        while frontier:
            next_level = []
            for i, j, state in frontier:
                # print(i, j, bin(state))
                if state == target:
                    return steps
                for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= ni < m and 0 <= nj < n and grid[ni][nj] != '#' and (grid[ni][nj] not in locks or state & (1 << (ord(grid[ni][nj]) - ord('A')))) != 0:
                        new_state = state | (1 << (ord(grid[ni][nj]) - ord('a'))) if grid[ni][nj] in keys else state
                        if (ni, nj, new_state) not in seen:
                            seen.add((ni, nj, new_state))
                            next_level.append((ni, nj, new_state))
            frontier = next_level
            steps += 1
        return -1
