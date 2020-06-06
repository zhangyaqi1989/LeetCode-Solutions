class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i, cur = 0, None
        for j, num in enumerate(nums):
            if num != cur:
                cur = num
                nums[i] = num
                i += 1
        return i