class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # n is at least two
        res = 0
        left, right = 0, len(height) - 1
        while left < right:
            while left < right and height[left] <= height[right]:
                res = max(res, height[left] * (right - left))
                left += 1
            while left < right and height[left] > height[right]:
                res = max(res, height[right] * (right - left))
                right -= 1
        return res