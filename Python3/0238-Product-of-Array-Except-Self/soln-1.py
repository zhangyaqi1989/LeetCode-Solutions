class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = [1] + list(itertools.accumulate(nums[:-1], operator.mul))
        acc = 1
        for i in range(len(nums) - 1, -1, -1):
            ans[i] *= acc
            acc *= nums[i]
        return ans
