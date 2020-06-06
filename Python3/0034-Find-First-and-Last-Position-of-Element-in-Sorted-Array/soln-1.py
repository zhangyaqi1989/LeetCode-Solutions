class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = bisect.bisect_left(nums, target), bisect.bisect_right(nums, target)
        return [l, r - 1] if l != r else [-1, -1] 