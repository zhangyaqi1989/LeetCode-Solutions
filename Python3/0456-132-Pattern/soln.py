class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        stack = []
        s3 = -float("inf")
        for n in nums[::-1]:
            if n < s3: return True
            while stack and stack[-1] < n: s3 = stack.pop()
            stack.append(n)
        return False