class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) == 1:
            return nums[0]
        def helper(nums):
            if not nums:
                return 0
            if len(nums) == 1:
                return nums[0]
            first, second = nums[0], max(nums[0], nums[1])
            for i in range(2, len(nums)):
                first, second = second, max(first + nums[i], second)
            return second
        return max(helper(nums[1:]), helper(nums[:-1]))