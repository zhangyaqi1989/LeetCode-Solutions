class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for key, group in itertools.groupby(nums):
            nums[i] = key
            i += 1
        return i