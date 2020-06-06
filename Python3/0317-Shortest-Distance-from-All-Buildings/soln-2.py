class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        # can pass only zero
        m, n = len(grid), len(grid[0])
        nbs = 0
        reaches = collections.Counter()
        distances = collections.defaultdict(int)
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val == 1:
                    bid = nbs
                    nbs += 1
                    frontier = [(i, j)]
                    levels = {(i, j) : 0}
                    step = 0
                    while frontier:
                        nxt_level = []
                        for r, c in frontier:
                            for nr, nc in (r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1):
                                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 0 and (nr, nc) not in levels:
                                    levels[nr, nc] = step + 1
                                    reaches[(nr, nc)] += 1
                                    distances[(nr, nc)] += step + 1
                                    nxt_level.append((nr, nc))
                        step += 1
                        frontier = nxt_level
        mn = math.inf
        for (i, j), cnt in reaches.items():
            if cnt == nbs and distances[(i, j)] < mn:
                mn = distances[(i, j)]
        return mn if mn != math.inf else -1
