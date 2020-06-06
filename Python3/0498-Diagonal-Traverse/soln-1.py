class Solution:
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not any(matrix):
            return []
        m, n = len(matrix), len(matrix[0])
        seeds = [(0, j) for j in range(n)] + [(i, n - 1) for i in range(1, m)]
        reverse = True
        ans = []
        for i, j in seeds:
            vals = []
            while i < m and j >= 0:
                vals.append(matrix[i][j])
                i += 1
                j -= 1
            if reverse:
                ans.extend(vals[::-1])
            else:
                ans.extend(vals)
            reverse = not reverse
        return ans