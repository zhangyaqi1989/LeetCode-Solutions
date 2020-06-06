class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper(lo, hi):
            pre, cur = 0, 0
            for i in range(lo, hi):
                pre, cur = cur, max(pre + nums[i], cur)
            return cur
        if len(nums) == 1:
            return nums[0]
        return max(helper(1, len(nums)), helper(0, len(nums)- 1))
