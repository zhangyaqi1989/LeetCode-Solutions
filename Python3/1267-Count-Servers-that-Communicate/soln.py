class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        h, w = len(grid), len(grid[0])
        rows = [0] * h
        cols = [0] * w
        cnt = 0
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                if val:
                    cnt += 1
                    rows[i] += 1
                    cols[j] += 1
        return cnt - sum(grid[i][j] == 1 and rows[i] == 1 and cols[j] == 1 for i in range(h) for j in range(w))
