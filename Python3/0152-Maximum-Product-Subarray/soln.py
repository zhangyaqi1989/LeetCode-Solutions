class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur_min, cur_max, res = nums[0], nums[0], nums[0]
        for num in nums[1:]:
            cur_min, cur_max = min(cur_max * num, cur_min * num, num), max(cur_max * num, cur_min * num, num)
            res = max(res, cur_max)
        return res