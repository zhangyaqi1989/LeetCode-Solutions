import numpy as np

class NumMatrix:

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        if not any(matrix):
            m, n = 0, 0
        else:
            m, n = len(matrix) + 1, len(matrix[0]) + 1
        self.acc = np.zeros((m, n), dtype=np.int64)
        for i in range(1, m):
            for j in range(1, n):
                self.acc[i, j] = matrix[i - 1][j - 1] + self.acc[i - 1, j] + self.acc[i, j - 1] - self.acc[i - 1, j - 1]
                

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return int(self.acc[row2 + 1, col2 + 1] + self.acc[row1, col1] - self.acc[row1, col2 + 1] - self.acc[row2 + 1, col1])