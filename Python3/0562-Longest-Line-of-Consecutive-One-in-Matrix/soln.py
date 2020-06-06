class Solution:
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        # 1. how to distinguish row, col, diag and anti_diag
        # 2. DP is suitable for optimization problem, look for sub_optimal
        if not M or not M[0]:
            return 0
        res = 0
        m, n = len(M), len(M[0])
        col = [0] * n
        diag = [0] * (m + n) # i + j
        anti_diag = [0] * (m + n) # j - i + m
        for i, item in enumerate(M):
            row = 0
            for j, val in enumerate(item):
                if val == 1:
                    row += 1
                    col[j] += 1
                    diag[i + j] += 1
                    anti_diag[j - i + m] += 1
                    res = max(res, row, col[j], diag[i + j], anti_diag[j - i + m])
                else:
                    row = 0
                    col[j] = 0
                    diag[i + j] = 0
                    anti_diag[j - i + m] = 0
        return res