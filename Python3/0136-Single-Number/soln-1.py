import functools
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return functools.reduce(lambda x, y: x ^ y, nums, 0)