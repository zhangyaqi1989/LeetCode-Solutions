class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # each integer [1, n]
        for num in nums:
            if nums[abs(num) - 1] < 0:
                return abs(num)
            else:
                nums[abs(num) - 1] = -abs(nums[abs(num) - 1])