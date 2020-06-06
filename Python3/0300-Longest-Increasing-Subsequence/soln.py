class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stack = []
        for num in nums:
            if not stack or num > stack[-1]:
                stack.append(num)
            else:
                idx = bisect.bisect_left(stack, num)
                stack[idx] = num
        return len(stack)