class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        heights.append(0)
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
        return mx
