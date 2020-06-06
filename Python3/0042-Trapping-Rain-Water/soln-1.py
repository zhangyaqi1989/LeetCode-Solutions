class Solution:
    def trap(self, height: List[int]) -> int:
        lo, hi = 0, len(height) - 1
        level = 0
        water = 0
        while lo < hi:
            while lo < hi and level >= height[lo]:
                water += level - height[lo]
                lo += 1
            while lo < hi and level >= height[hi]:
                water += level - height[hi]
                hi -= 1
            level = min(height[lo], height[hi])
        return water
