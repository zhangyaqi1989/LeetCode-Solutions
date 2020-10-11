class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        H, W = len(rowSum), len(colSum)
        mat = [[0] * W for _ in range(H)]
        for i in range(H):
            for j in range(W):
                mat[i][j] = min(rowSum[i], colSum[j])
                rowSum[i] -= mat[i][j]
                colSum[j] -= mat[i][j]
        return mat
