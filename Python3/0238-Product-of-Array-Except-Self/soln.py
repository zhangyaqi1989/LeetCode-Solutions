class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = [1]
        for num in nums[:-1]:
            ans.append(ans[-1] * num)
        acc = 1
        for j in range(len(nums) - 1, -1, -1):
            ans[j] *= acc
            acc *= nums[j]
        return ans