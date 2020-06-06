import functools
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ab_xor = functools.reduce(operator.ixor, nums)
        bit = ab_xor & (-ab_xor)
        ans = [0, 0]
        for num in nums:
            if num & bit > 0:
                ans[0] ^= num
            else:
                ans[1] ^= num
        return ans