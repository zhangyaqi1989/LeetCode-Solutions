class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre, cur = 0, 0
        for num in nums:
            pre, cur = cur, max(pre + num, cur)
        return cur
