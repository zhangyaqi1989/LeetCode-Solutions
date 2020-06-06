class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for num, _ in itertools.groupby(nums):
            nums[i] = num
            i += 1
        return i