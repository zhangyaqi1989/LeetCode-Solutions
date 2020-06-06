class Solution:
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sort_nums = sorted(nums)
        i, j, n = 0, len(nums) - 1, len(nums)
        while i < n and nums[i] == sort_nums[i]:
            i += 1
        while j > i and nums[j] == sort_nums[j]:
            j -= 1
        return j - i + 1