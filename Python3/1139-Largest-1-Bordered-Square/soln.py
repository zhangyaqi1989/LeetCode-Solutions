class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        mx = 0
        m, n = len(grid), len(grid[0])
        hor = [[0] * n for _ in range(m)]
        ver = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    ver[i][j], hor[i][j] = 0, 0
                else:
                    if i == 0:
                        ver[i][j] = 1
                    else:
                        ver[i][j] = ver[i - 1][j] + 1
                    if j == 0:
                        hor[i][j] = 1
                    else:
                        hor[i][j] = hor[i][j - 1] + 1
        for i in reversed(range(m)):
            for j in reversed(range(n)):
                mn = min(hor[i][j], ver[i][j])
                while mn > mx:
                    if ver[i][j - mn + 1] >= mn and hor[i - mn + 1][j] >= mn:
                        mx = mn
                    mn -= 1
        return mx * mx
