class NumMatrix:

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        for row in matrix:
            for col in range(1, len(row)):
                row[col] += row[col - 1]
        self.matrix = matrix
        

    def update(self, row, col, val):
        """
        :type row: int
        :type col: int
        :type val: int
        :rtype: void
        """
        old_val = (self.matrix[row][col] - self.matrix[row][col - 1]) if col > 0 else self.matrix[row][col]
        diff = val - old_val
        if diff:
            for j in range(col, len(self.matrix[row])):
                self.matrix[row][j] += diff
        

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        ans = 0
        for i in range(row1, row2 + 1):
            ans += self.matrix[i][col2]
            if col1 > 0:
                ans -= self.matrix[i][col1 - 1]
        return ans
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)