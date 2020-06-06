class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # all positive
        prod = 1
        i = 0
        res = 0
        for j, num in enumerate(nums):
            prod *= num
            while prod >= k and j > i:
                prod /= nums[i]
                i += 1
            if prod < k:
                res += j - i + 1
        return res