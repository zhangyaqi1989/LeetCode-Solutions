class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        if not any(grid):
            return 0
        m, n = len(grid), len(grid[0])
        kills = [[0] * n for _ in range(m)]
        for i in range(m):
            left = 0
            for j in range(n):
                if grid[i][j] == '0':
                    kills[i][j] += left
                elif grid[i][j] == 'E':
                    left += 1
                else:
                    left = 0
            right = 0
            for j in reversed(range(n)):
                if grid[i][j] == '0':
                    kills[i][j] += right
                elif grid[i][j] == 'E':
                    right += 1
                else:
                    right = 0
        for j in range(n):
            up = 0
            for i in range(m):
                if grid[i][j] == '0':
                    kills[i][j] += up
                elif grid[i][j] == 'E':
                    up += 1
                else:
                    up = 0
            down = 0
            for i in reversed(range(m)):
                if grid[i][j] == '0':
                    kills[i][j] += down
                elif grid[i][j] == 'E':
                    down += 1
                else:
                    down = 0
        return max(map(max, kills))
