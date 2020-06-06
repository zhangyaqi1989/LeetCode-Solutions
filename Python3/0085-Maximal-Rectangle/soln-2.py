class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        def helper(heights):
            heights.append(0)
            stack = []
            mx = 0
            for i, h in enumerate(heights):
                while stack and h < heights[stack[-1]]:
                    height = heights[stack.pop()]
                    if stack:
                        left = stack[-1]
                    else:
                        left = -1
                    width = i - left - 1
                    mx = max(mx, height * width)
                stack.append(i)
            heights.pop()
            return mx
        if not any(matrix):
            return 0
        m, n = len(matrix), len(matrix[0])
        heights = [[0] * n for _ in range(m)]
        for j in range(n):
            if matrix[0][j] == '1':
                heights[0][j] = 1
        for i in range(1, m):
            for j in range(n):
                if matrix[i][j] == '1':
                    heights[i][j] = heights[i - 1][j] + 1
        return max(helper(row) for row in heights)
