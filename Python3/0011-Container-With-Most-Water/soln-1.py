class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        lo, hi = 0, n - 1
        water = 0
        while lo < hi:
            w = hi - lo
            if height[lo] <= height[hi]:
                h = height[lo]
                lo += 1
            else:
                h = height[hi]
                hi -= 1
            water = max(water, h * w)
        return water
