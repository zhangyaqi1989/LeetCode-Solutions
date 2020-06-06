class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not any(matrix):
            return 0
        m, n = len(matrix), len(matrix[0])
        heights = [0] * n
        mx = 0;
        for i, row in enumerate(matrix):
            for j, val in enumerate(row):
                if val == "1":
                    heights[j] += 1
                else:
                    heights[j] = 0
            mx = max(mx, self.largestRectangle(heights))
        return mx
        
        
    def largestRectangle(self, heights):
        stack = [-1]
        heights.append(0)
        mx = 0
        for i, h in enumerate(heights):
            while stack and h < heights[stack[-1]]:
                height = heights[stack.pop()]
                width = i - stack[-1] - 1
                mx = max(mx, height * width)
            stack.append(i)
        heights.pop()
        return mx
        
