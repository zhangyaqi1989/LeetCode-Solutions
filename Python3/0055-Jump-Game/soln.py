class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max_pos = 0
        for i, num in enumerate(nums):
            if max_pos < i: break
            max_pos = max(max_pos, i + num)
            if max_pos >= len(nums) - 1:
                return True
        return max_pos >= len(nums) - 1