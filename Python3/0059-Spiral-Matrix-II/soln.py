class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        res = [[0] * n for _ in range(n)]
        i = 1
        r, c = 0, 0
        dr, dc = 0, 1 # --> 1, 0
        while i <= n * n:
            res[r][c] = i
            if r + dr < 0 or r + dr >= n or c + dc < 0 or c + dc >= n or res[r+dr][c+dc]:
                dr, dc = dc, -dr
            r, c = r + dr, c + dc
            i += 1
        return res