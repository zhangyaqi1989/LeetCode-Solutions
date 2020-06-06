class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        col_zero = any(matrix[i][0] == 0 for i in range(m))
        row_zero = any(matrix[0][j] == 0 for j in range(n))
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if col_zero:
            for i in range(m):
                matrix[i][0] = 0
        if row_zero:
            for j in range(n):
                matrix[0][j] = 0