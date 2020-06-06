class Solution:
    def minTotalDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def helper(vec):
            i, j = -1, len(vec)
            left, right, d = 0, 0, 0
            while i < j:
                if left < right:
                    d += left
                    i += 1 
                    left += vec[i]
                else:
                    d += right
                    j -= 1
                    right += vec[j]
            return d
        row_sum = list(map(sum, grid))
        col_sum = list(map(sum, zip(*grid)))
        return helper(row_sum) + helper(col_sum)