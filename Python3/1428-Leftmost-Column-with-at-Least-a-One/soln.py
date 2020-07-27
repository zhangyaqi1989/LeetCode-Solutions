# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        rows, cols = binaryMatrix.dimensions()
        def valid(col):
            return any(binaryMatrix.get(row, col) for row in range(rows))
        lo, hi = 0, cols - 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if valid(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo if valid(lo) else -1
