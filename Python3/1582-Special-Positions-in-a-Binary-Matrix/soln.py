class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        R, C = len(mat), len(mat[0])
        rows = [0] * R
        cols = [0] * C
        for i, row in enumerate(mat):
            for j, val in enumerate(row):
                if val == 1:
                    rows[i] += 1
                    cols[j] += 1
        return sum(mat[r][c] == 1 and rows[r] == 1 and cols[c] == 1 for r in range(R) for c in range(C))
