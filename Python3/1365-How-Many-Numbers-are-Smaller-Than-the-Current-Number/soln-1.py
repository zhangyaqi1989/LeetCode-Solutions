class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        copy_nums = sorted(nums)
        return [bisect.bisect_right(copy_nums, num - 1) for num in nums]
