class Solution:
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        # positive integers
        if len(nums) == 1:
            return '{}'.format(nums[0])
        if len(nums) == 2:
            return '{}/{}'.format(nums[0], nums[1])
        return '{}/({})'.format(nums[0], '/'.join(map(str, nums[1:])))