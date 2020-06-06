class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper(i, j):
            print(nums[i:j + 1])
            if j < i: return 0
            elif j - i <= 1: return max(nums[i:j + 1])
            else:
                first, second = nums[i], max(nums[i + 1], nums[i])
                for num in nums[i + 2:j + 1]:
                    first, second = second, max(second, num + first)
                return second
        if len(nums) == 1: return nums[0]
        return max(helper(0, len(nums) - 2), helper(1, len(nums) - 1))