class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        heights.append(0)
        mx = 0
        for i, h in enumerate(heights):
            while h < heights[stack[-1]]:
                height = heights[stack.pop()]
                width = i - stack[-1] - 1
                mx = max(mx, height * width)
            stack.append(i)
        return mx
