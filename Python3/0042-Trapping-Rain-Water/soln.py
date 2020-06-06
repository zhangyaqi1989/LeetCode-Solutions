class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height) - 1
        min_height = 0
        res = 0
        while l < r:
            while l < r and height[l] <= min_height:
                res += min_height - height[l]
                l += 1
            while l < r and height[r] <= min_height:
                res += min_height - height[r]
                r -= 1
            min_height = min(height[l], height[r])
        return res