class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        m, n = len(matrix), len(matrix[0])
        starters = [(0, j) for j in range(n)] + [(i, n - 1) for i in range(1, m)]
        res = []
        reverse = True
        di, dj = +1, -1
        for i, j in starters:
            vals = []
            while i < m and j >= 0:
                vals.append(matrix[i][j])
                i, j = i + di, j + dj
            if reverse:
                res.extend(vals[::-1])
            else:
                res.extend(vals)
            reverse = not reverse
        return res