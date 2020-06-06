class Solution:
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # this is rectangle not square
        if not any(matrix):
            return 0
        m, n = len(matrix), len(matrix[0])
        heights = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    heights[i][j] = heights[i - 1][j] + 1
        return max(self.helper(row) for row in heights)
    def helper(self, height):
        height.append(0)
        stack = [-1]
        ans = 0
        for idx, H in enumerate(height):
            while height[stack[-1]] > H:
                h = height[stack.pop()]
                w = idx - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(idx)
        return ans