class Solution:
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for num in nums:
            if nums[abs(num) - 1] < 0:
                dup = abs(num)
            else:
                nums[abs(num) - 1] = -nums[abs(num) - 1]
        for idx, num in enumerate(nums):
            if num > 0:
                miss = idx + 1
        return dup, miss