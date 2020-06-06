class Solution:
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        memo = {}
        def score(s, start, end):
            if (start, end) in memo:
                return memo[start, end]
            if start == end:
                memo[start, end] = nums[start]
                return nums[start]
            left = s - score(s - nums[start], start + 1, end)
            right = s - score(s - nums[end], start, end - 1)
            memo[start, end] = max(left, right)
            return memo[start, end]
        s = sum(nums)
        return score(s, 0, len(nums) - 1) >= s / 2 