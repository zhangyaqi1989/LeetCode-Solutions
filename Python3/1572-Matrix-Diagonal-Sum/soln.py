class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        ans = 0
        n = len(mat)
        for i in range(n):
            ans += mat[i][i]
            ans += mat[n - 1 - i][i]
        return ans - (0 if n % 2 == 0 else mat[n // 2][n // 2])
