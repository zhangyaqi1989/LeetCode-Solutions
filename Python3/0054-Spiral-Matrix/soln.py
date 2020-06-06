class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        return list(matrix.pop(0)) + self.spiralOrder(list(zip(*matrix))[::-1])