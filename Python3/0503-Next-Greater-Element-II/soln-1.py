class Solution:
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # use stack
        n, stack = len(nums), []
        ans = [-1] * n
        for idx, num in enumerate(itertools.chain(nums, nums)):
            i = idx % n
            while stack and num > nums[stack[-1]]:
                ans[stack.pop()] = num
            stack.append(i)
        return ans