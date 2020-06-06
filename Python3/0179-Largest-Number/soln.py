import functools
class Solution:
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        comp=lambda a, b: -1 if a+b > b+a else 1 if a+b<b+a else 0
        return str(int(''.join(sorted(map(str, nums), key=functools.cmp_to_key(comp)))))