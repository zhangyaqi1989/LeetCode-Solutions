class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if not any(matrix):
            return
        m, n = len(matrix), len(matrix[0])
        self.tree = [[0] * (n + 1) for _ in range(m + 1)]
        self.R = m + 1
        self.C = n + 1
        for i in range(m):
            for j in range(n):
                self.add(i + 1, j + 1, matrix[i][j])
        self.matrix = matrix
        
    def add(self, row, col, val):
        i = row
        while i < self.R:
            j = col
            while j < self.C:
                self.tree[i][j] += val
                j += (j & (-j))
            i += (i & (-i))
    
    def sumRange(self, row, col):
        ans = 0
        i = row
        while i > 0:
            j = col
            while j > 0:
                ans += self.tree[i][j]
                j -= (j & (-j))
            i -= (i & (-i))
        return ans

    def update(self, row: int, col: int, val: int) -> None:
        self.add(row + 1, col + 1, val - self.matrix[row][col])
        self.matrix[row][col] = val

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.sumRange(row2 + 1, col2 + 1) - self.sumRange(row2 + 1, col1) - self.sumRange(row1, col2 + 1) + self.sumRange(row1, col1)


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
