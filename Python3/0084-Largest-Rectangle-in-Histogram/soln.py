class Solution:
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights += [0]
        stack = [-1]
        ans = 0
        for i, height in enumerate(heights):
            while height < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(i)
        heights.pop()
        return ans


if __name__ == '__main__':
    soln = Solution()
    arr = [3, 1, 3, 2, 2]
    print(soln.largestRectangleArea(arr))
