class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # a ^ b
        ab_xor = functools.reduce(operator.ixor, nums)
        bit = ab_xor & (-ab_xor)
        return functools.reduce(operator.ixor, filter(lambda x : x & bit > 0, nums)), functools.reduce(operator.ixor, filter(lambda x : x & bit == 0, nums))