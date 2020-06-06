class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [-1] * len(nums)
        stack = []
        n = len(nums)
        for idx, num in enumerate(nums + nums):
            idx %= n
            while stack and num > nums[stack[-1]]:
                res[stack.pop()] = num
            stack.append(idx)
        return res