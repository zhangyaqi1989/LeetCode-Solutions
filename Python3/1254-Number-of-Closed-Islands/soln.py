class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        def fill(r, c, old_value, new_value):
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or grid[r][c] != old_value:
                return
            grid[r][c] = new_value
            fill(r - 1, c, old_value, new_value)
            fill(r + 1, c, old_value, new_value)
            fill(r, c - 1, old_value, new_value)
            fill(r, c + 1, old_value, new_value)
        h, w = len(grid), len(grid[0])
        for c in range(w):
            fill(0, c, 0, 1)
            fill(h - 1, c, 0, 1)
        for r in range(h):
            fill(r, 0, 0, 1)
            fill(r, w - 1, 0, 1)
        cnt = 0
        for r in range(h):
            for c in range(w):
                if grid[r][c] == 0:
                    cnt += 1
                    fill(r, c, 0, 1)
        return cnt
