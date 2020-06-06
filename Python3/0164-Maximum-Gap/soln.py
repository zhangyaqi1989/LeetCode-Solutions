class Solution:
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # linear time
        if len(nums) < 2:
            return 0
        nums = sorted(nums)
        return max(nums[i] - nums[i - 1] for i in range(1, len(nums)))
