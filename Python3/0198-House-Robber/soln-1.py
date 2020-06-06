class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        elif len(nums) <= 2:
            return max(nums)
        else:
            first, second = nums[0], max(nums[0], nums[1])
            for num in nums[2:]:
                first, second = second, max(num + first, second)
            return second
        