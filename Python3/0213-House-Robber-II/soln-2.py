class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper(array):
            pre, cur = 0, 0
            for num in array:
                pre, cur = cur, max(pre + num, cur)
            return cur
        if len(nums) == 1:
            return nums[0]
        return max(helper(nums[1:]), helper(nums[:-1]))
