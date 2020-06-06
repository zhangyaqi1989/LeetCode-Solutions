class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for num, g in itertools.groupby(nums):
            n = min(2, len(list(g)))
            nums[i:i + n] = [num] * n
            i += n
        return i