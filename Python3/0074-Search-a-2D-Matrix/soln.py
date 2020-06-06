class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        # the matrix is ordered in row-order traverse
        # 2D matrix could be seen as 1D array
        if not matrix or not matrix[0]:
            return False
        m, n = len(matrix), len(matrix[0])
        lo, hi = 0, m * n - 1
        if target < matrix[0][0] or target > matrix[-1][-1]:
            return False
        while lo <= hi:
            mid = (lo + hi) >> 1
            r, c = mid // n, mid % n
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return False