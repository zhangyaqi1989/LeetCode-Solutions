class Solution:
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        up = down = 1
        for i in range(0, len(nums) - 1):
            a, b = nums[i], nums[i + 1]
            if a < b:
                up, down = down + 1, down
            elif a > b:
                up, down = up, up + 1
        return max(up, down)
