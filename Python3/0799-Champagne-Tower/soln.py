class Solution:
    def champagneTower(self, poured, query_row, query_glass):
        """
        :type poured: int
        :type query_row: int
        :type query_glass: int
        :rtype: float
        """
        # index starts from zero
        res = [poured] + [0] * 100
        for row in range(1, query_row + 1):
            for j in range(row, -1, -1):
                res[j] = max(res[j] - 1, 0) / 2 + max(res[j - 1] - 1, 0) / 2
        return min(res[query_glass], 1)