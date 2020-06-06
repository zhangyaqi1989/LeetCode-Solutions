class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur, res = float('-inf'), float('-inf')
        for num in nums:
            cur = max(num, cur + num)
            res = max(res, cur)
        return res