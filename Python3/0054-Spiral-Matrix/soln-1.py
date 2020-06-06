class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        ans = []
        m, n = len(matrix), len(matrix[0])
        i, j, di, dj, cnt = 0, 0, 0, 1, 0
        while cnt < m * n:
            ans.append(matrix[i][j])
            matrix[i][j] = None
            newi, newj = i + di, j + dj
            if newi < 0 or newi >= m or newj < 0 or newj >= n or matrix[newi][newj] == None:
                di, dj = dj, -di
            i, j = i + di, j + dj
            cnt += 1
        return ans