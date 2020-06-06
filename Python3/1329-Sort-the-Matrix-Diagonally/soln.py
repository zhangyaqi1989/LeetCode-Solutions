class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        diags = collections.defaultdict(list)
        for i, row in enumerate(mat):
            for j, val in enumerate(row):
                diags[i - j].append(val)
        for _, lst in diags.items():
            lst.sort(reverse=True)
        for i in range(m):
            for j in range(n):
                mat[i][j] = diags[i - j].pop()
        return mat
