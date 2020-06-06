class Solution:
    def canJump(self, nums: List[int]) -> bool:
        farthest = 0
        n = len(nums)
        for i, num in enumerate(nums):
            if farthest < i:
                return False
            farthest = max(farthest, i + num)
            if farthest >= n - 1:
                return True
        return farthest >= n - 1
