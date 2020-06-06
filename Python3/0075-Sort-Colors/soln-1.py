class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lo, cur, hi = 0, 0, len(nums) - 1
        while cur <= hi:
            if nums[cur] == 0:
                nums[lo], nums[cur] = nums[cur], nums[lo]
                lo += 1
                cur += 1
            elif nums[cur] == 2:
                nums[cur], nums[hi] = nums[hi], nums[cur]
                hi -= 1
            else:
                cur += 1
