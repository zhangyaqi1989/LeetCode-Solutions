class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # use nums as dictionary
        ans = []
        for num in nums:
            nums[abs(num) - 1] = -abs(nums[abs(num) - 1])
        return [i + 1 for i, num in enumerate(nums) if num > 0]