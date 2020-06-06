import functools
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return functools.reduce(operator.ixor, nums, 0)
        