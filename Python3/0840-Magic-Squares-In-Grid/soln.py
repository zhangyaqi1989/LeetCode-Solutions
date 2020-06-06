class Solution:
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def isMagic(sub):
            if sub[1][1] != 5: return False
            vals = [1] + [0] * 9
            for i in range(3):
                for j in range(3):
                    if 1 <= sub[i][j] <= 9:
                        vals[sub[i][j]] = 1
                    else:
                        return False
            if not all(vals): return False
            if sub[0][0] + sub[0][1] + sub[0][2] != 15: return False
            if sub[1][0] + sub[1][1] + sub[1][2] != 15: return False
            if sub[2][0] + sub[2][1] + sub[2][2] != 15: return False
            if sub[0][0] + sub[1][0] + sub[2][0] != 15: return False
            if sub[0][1] + sub[1][1] + sub[2][1] != 15: return False
            if sub[0][2] + sub[1][2] + sub[2][2] != 15: return False
            if sub[0][0] + sub[1][1] + sub[2][2] != 15: return False
            if sub[2][0] + sub[1][1] + sub[0][2] != 15: return False
            return True
        m, n = len(grid), len(grid[0])
        return sum( isMagic([[grid[i + di][j + dj] for dj in (0, 1, 2)] for di in (0, 1, 2)])
                    for i in range(m - 2)
                    for j in range(n - 2))
