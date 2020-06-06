# 2D fenwick tree
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if not any(matrix):
            m, n = 0, 0
            return
        m, n = len(matrix), len(matrix[0])
        self.matrix = matrix
        self.tree = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                self.add(i + 1, j + 1, matrix[i][j])
    
    def add(self, i, j, val):
        if val == 0:
            return
        r = i
        while r < len(self.tree):
            c = j
            while c < len(self.tree[0]):
                self.tree[r][c] += val
                c += (c & (-c))
            r += (r & (-r))
    
    def acc(self, i, j):
        ans = 0
        r = i
        while r > 0:
            c = j
            while c > 0:
                ans += self.tree[r][c]
                c -= (c & (-c))
            r -= (r & (-r))
        return ans
                
        
    def update(self, row: int, col: int, val: int) -> None:
        self.add(row + 1, col + 1, val - self.matrix[row][col])
        self.matrix[row][col] = val

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.acc(row2 + 1, col2 + 1) + self.acc(row1, col1) - self.acc(row1, col2 + 1) - self.acc(row2 + 1, col1)


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# obj.update(row,col,val)
# param_2 = obj.sumRegion(row1,col1,row2,col2)
