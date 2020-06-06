class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # contains duplicates
        nums = sorted(nums)
        ans = [[]]
        for num in nums:
            ans = [item[:i] + [num] + item[i:] for item in ans for i in range((item + [num]).index(num) + 1)]
        return ans
