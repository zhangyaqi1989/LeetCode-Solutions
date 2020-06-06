class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start, end, n, step = 0, 0, len(nums), 0
        while end < n - 1:
            start, end = end + 1, max(i + nums[i] for i in range(start, end + 1))
            step += 1
        return step
