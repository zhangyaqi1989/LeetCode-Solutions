class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        for i in range(n - 1):
            for j in range(n - 1 - i):
                matrix[i][j], matrix[m - 1 - j][n - 1 - i] = matrix[m - 1 - j][n - 1 - i], matrix[i][j]
        for i in range(m // 2):
            matrix[i], matrix[~i] = matrix[~i], matrix[i]