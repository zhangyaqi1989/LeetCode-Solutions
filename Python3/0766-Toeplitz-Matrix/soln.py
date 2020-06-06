class Solution:
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        return all(matrix[i][j] == matrix[i + 1][j + 1] for i in range(len(matrix) - 1) for j in range(len(matrix[0]) - 1))